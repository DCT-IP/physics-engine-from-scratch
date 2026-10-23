
#include <iostream>
#include <cassert>
#include <cmath>
#include <memory>

#include "BodySystem.h"
#include "Gravity.h"

using Math::Vec2;

bool nearlyEqual(float a, float b, float epsilon = 0.0001f)
{
    return std::fabs(a - b) < epsilon;
}

void testBodyManagement()
{
    BodySystem system;

    system.addBody(
        std::make_unique<Body>(Vec2(0.0f, 0.0f), 1.0f)
    );

    system.addBody(
        std::make_unique<Body>(Vec2(5.0f, 5.0f), 2.0f)
    );

    assert(system.getBodyCount() == 2);

    std::cout << "[PASS] Body management\n";
}

void testRegisteredGravity()
{
    BodySystem system;

    Body& body = system.addBody(
        std::make_unique<Body>(Vec2(0.0f, 0.0f), 2.0f)
    );

    Gravity gravity(Vec2(0.0f, -10.0f));

    system.addForceGenerator(body, gravity);
    system.update(1.0f);

    assert(nearlyEqual(body.getVelocity().y, -10.0f));
    assert(nearlyEqual(body.getPosition().y, -10.0f));

    std::cout << "[PASS] Registered gravity\n";
}

void testGravityReappliedEachUpdate()
{
    BodySystem system;

    Body& body = system.addBody(
        std::make_unique<Body>(Vec2(0.0f, 0.0f), 1.0f)
    );

    Gravity gravity(Vec2(0.0f, -10.0f));
    system.addForceGenerator(body, gravity);

    system.update(1.0f);
    system.update(1.0f);

    assert(nearlyEqual(body.getVelocity().y, -20.0f));
    assert(nearlyEqual(body.getPosition().y, -30.0f));

    std::cout << "[PASS] Gravity reapplied each update\n";
}

void testUnregisteredBodyUnaffected()
{
    BodySystem system;

    Body& affected = system.addBody(
        std::make_unique<Body>(Vec2(0.0f, 0.0f), 1.0f)
    );

    Body& unaffected = system.addBody(
        std::make_unique<Body>(Vec2(5.0f, 5.0f), 1.0f)
    );

    Gravity gravity(Vec2(0.0f, -10.0f));
    system.addForceGenerator(affected, gravity);

    system.update(1.0f);

    assert(nearlyEqual(affected.getVelocity().y, -10.0f));
    assert(nearlyEqual(unaffected.getVelocity().y, 0.0f));
    assert(nearlyEqual(unaffected.getPosition().y, 5.0f));

    std::cout << "[PASS] Unregistered body unaffected\n";
}

int main()
{
    std::cout << "=== Body System Tests ===\n\n";

    testBodyManagement();
    testRegisteredGravity();
    testGravityReappliedEachUpdate();
    testUnregisteredBodyUnaffected();

    std::cout << "\nAll Body System tests passed!\n";
    return 0;
}
