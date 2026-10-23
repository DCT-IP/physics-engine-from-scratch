
#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>

#include "Body.h"
#include "SemiImplicitEuler.h"

using Math::Vec2;

bool nearlyEqual(float a, float b, float epsilon = 0.0001f)
{
    return std::fabs(a - b) < epsilon;
}

void assertVec2Equal(
    const Vec2& actual,
    const Vec2& expected,
    float epsilon = 0.0001f
)
{
    assert(nearlyEqual(actual.x, expected.x, epsilon));
    assert(nearlyEqual(actual.y, expected.y, epsilon));
}

void testAccelerationFromForce()
{
    Body body(Vec2(0.0f, 0.0f), 2.0f);
    SemiImplicitEuler integrator;

    body.applyForce(Vec2(10.0f, 0.0f));
    integrator.integrate(body, 0.0f);

    assertVec2Equal(
        body.getAcceleration(),
        Vec2(5.0f, 0.0f)
    );

    std::cout << "[PASS] Acceleration from force\n";
}

void testVelocityUpdate()
{
    Body body(Vec2(0.0f, 0.0f), 2.0f);
    SemiImplicitEuler integrator;

    body.applyForce(Vec2(10.0f, 0.0f));
    integrator.integrate(body, 1.0f);

    // a = F / m = 5
    // v' = v + a * dt = 5

    assertVec2Equal(
        body.getVelocity(),
        Vec2(5.0f, 0.0f)
    );

    std::cout << "[PASS] Velocity update\n";
}

void testPositionUpdate()
{
    Body body(Vec2(0.0f, 0.0f), 1.0f);
    SemiImplicitEuler integrator;

    body.applyForce(Vec2(10.0f, 0.0f));
    integrator.integrate(body, 0.1f);

    // a = 10
    // v' = 1
    // x' = 0.1

    assertVec2Equal(
        body.getVelocity(),
        Vec2(1.0f, 0.0f)
    );

    assertVec2Equal(
        body.getPosition(),
        Vec2(0.1f, 0.0f)
    );

    std::cout << "[PASS] Semi-implicit Euler position update\n";
}

void testForceAccumulation()
{
    Body body(Vec2(0.0f, 0.0f), 2.0f);
    SemiImplicitEuler integrator;

    body.applyForce(Vec2(10.0f, 0.0f));
    body.applyForce(Vec2(0.0f, 10.0f));

    integrator.integrate(body, 1.0f);

    assertVec2Equal(
        body.getVelocity(),
        Vec2(5.0f, 5.0f)
    );

    std::cout << "[PASS] Force accumulation\n";
}

void testForceClearing()
{
    Body body(Vec2(0.0f, 0.0f), 1.0f);
    SemiImplicitEuler integrator;

    body.applyForce(Vec2(10.0f, 0.0f));
    integrator.integrate(body, 1.0f);

    // No new force: velocity should remain unchanged.
    integrator.integrate(body, 1.0f);

    assertVec2Equal(
        body.getVelocity(),
        Vec2(10.0f, 0.0f)
    );

    std::cout << "[PASS] Force clearing\n";
}

void testZeroForce()
{
    Body body(Vec2(5.0f, 5.0f), 2.0f);
    SemiImplicitEuler integrator;

    integrator.integrate(body, 1.0f);

    assertVec2Equal(
        body.getVelocity(),
        Vec2(0.0f, 0.0f)
    );

    assertVec2Equal(
        body.getPosition(),
        Vec2(5.0f, 5.0f)
    );

    std::cout << "[PASS] Zero force\n";
}

void testZeroMassBody()
{
    Body body(Vec2(2.0f, 3.0f), 0.0f);
    SemiImplicitEuler integrator;

    body.applyForce(Vec2(100.0f, 100.0f));
    integrator.integrate(body, 1.0f);

    assertVec2Equal(
        body.getPosition(),
        Vec2(2.0f, 3.0f)
    );

    assertVec2Equal(
        body.getVelocity(),
        Vec2(0.0f, 0.0f)
    );

    // A static body must not retain stale forces.
    integrator.integrate(body, 1.0f);

    assertVec2Equal(
        body.getPosition(),
        Vec2(2.0f, 3.0f)
    );

    std::cout << "[PASS] Zero-mass body\n";
}

void testZeroTimestep()
{
    Body body(Vec2(0.0f, 0.0f), 1.0f);
    SemiImplicitEuler integrator;

    body.applyForce(Vec2(10.0f, 0.0f));
    integrator.integrate(body, 0.0f);

    assertVec2Equal(
        body.getAcceleration(),
        Vec2(10.0f, 0.0f)
    );

    assertVec2Equal(
        body.getVelocity(),
        Vec2(0.0f, 0.0f)
    );

    assertVec2Equal(
        body.getPosition(),
        Vec2(0.0f, 0.0f)
    );

    std::cout << "[PASS] Zero timestep\n";
}

void testInvalidTimestep()
{
    SemiImplicitEuler integrator;

    Body negativeDtBody(Vec2(0.0f, 0.0f), 1.0f);
    bool negativeDtRejected = false;

    try {
        integrator.integrate(negativeDtBody, -1.0f);
    }
    catch (const std::invalid_argument&) {
        negativeDtRejected = true;
    }

    assert(negativeDtRejected);

    Body nanDtBody(Vec2(0.0f, 0.0f), 1.0f);
    bool nanDtRejected = false;

    try {
        integrator.integrate(
            nanDtBody,
            std::nanf("")
        );
    }
    catch (const std::invalid_argument&) {
        nanDtRejected = true;
    }

    assert(nanDtRejected);

    std::cout << "[PASS] Invalid timestep rejected\n";
}

int main()
{
    std::cout << "=== SemiImplicitEuler Tests ===\n\n";

    testAccelerationFromForce();
    testVelocityUpdate();
    testPositionUpdate();
    testForceAccumulation();
    testForceClearing();
    testZeroForce();
    testZeroMassBody();
    testZeroTimestep();
    testInvalidTimestep();

    std::cout << "\nAll SemiImplicitEuler tests passed!\n";

    return 0;
}
