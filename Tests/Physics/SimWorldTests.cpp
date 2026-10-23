#include "../../Physics/SimulationWorld.h"
#include "../../Physics/Body.h"
#include "../../Physics/Gravity.h"
#include "../../Physics/ConstantForce.h"
#include "../../Core/Math/Vec2.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <memory>
#include <stdexcept>

bool near(float a, float b, float epsilon = 0.001f)
{
    return std::fabs(a - b) < epsilon;
}

void testInitialState()
{
    SimulationWorld world;

    assert(world.getBodyCount() == 0);
    assert(near(world.getFixedDeltaTime(), 1.0f / 60.0f));
    assert(near(world.getAccumulator(), 0.0f));
}

void testAddBody()
{
    SimulationWorld world;

    world.addBody(
        std::make_unique<Body>(Math::Vec2(0.0f, 0.0f), 1.0f)
    );

    assert(world.getBodyCount() == 1);
}

void testFixedTimestepAdvance()
{
    SimulationWorld world(0.1f);
    Body& body = world.addBody(
        std::make_unique<Body>(Math::Vec2(0.0f, 0.0f), 1.0f)
    );

    // No complete step yet.
    assert(world.advance(0.05f) == 0);

    // The accumulated time now reaches one fixed step.
    assert(world.advance(0.05f) == 1);
    assert(near(world.getAccumulator(), 0.0f));

    (void)body;
}

void testGravityIntegration()
{
    SimulationWorld world(0.1f);

    Body& body = world.addBody(
        std::make_unique<Body>(Math::Vec2(0.0f, 10.0f), 1.0f)
    );

    world.addForceGenerator(
        body,
        std::make_unique<Gravity>(Math::Vec2(0.0f, -10.0f))
    );

    const std::size_t steps = world.advance(0.1f);

    assert(steps == 1);
    assert(near(body.getVelocity().y, -1.0f));
    assert(near(body.getPosition().y, 9.9f));
}

void testResetTime()
{
    SimulationWorld world(0.1f);

    world.advance(0.05f);
    assert(near(world.getAccumulator(), 0.05f));

    world.resetTime();
    assert(near(world.getAccumulator(), 0.0f));
}

void testMaximumSubsteps()
{
    SimulationWorld world(0.1f, 2);

    const std::size_t steps = world.advance(0.5f);

    assert(steps == 2);
    assert(world.getAccumulator() < world.getFixedDeltaTime());
}

void testInvalidGenerator()
{
    SimulationWorld world;

    Body& body = world.addBody(
        std::make_unique<Body>(Math::Vec2(0.0f, 0.0f), 1.0f)
    );

    bool threw = false;

    try {
        world.addForceGenerator(
            body,
            std::unique_ptr<ForceGenerator>{}
        );
    }
    catch (const std::invalid_argument&) {
        threw = true;
    }

    assert(threw);
}

int main()
{
    testInitialState();
    testAddBody();
    testFixedTimestepAdvance();
    testGravityIntegration();
    testResetTime();
    testMaximumSubsteps();
    testInvalidGenerator();

    std::cout << "All SimulationWorld tests passed\n";
    return 0;
}
