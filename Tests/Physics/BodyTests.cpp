#include <iostream>
#include <cassert>
#include <cmath>


#include "Body.h"

using Math::Vec2;
    bool nearlyEqual(float a, float b, float epsilon = 0.0001f)
{
    return std::fabs(a - b) < epsilon;
}

void assertVec2Equal(const Vec2& actual, const Vec2& expected,
                     float epsilon = 0.0001f)
{
    assert(nearlyEqual(actual.x, expected.x, epsilon));
    assert(nearlyEqual(actual.y, expected.y, epsilon));
}


void testBodyConstruction()
{
    Vec2 initialPosition(5.0f, 10.0f);
    float mass = 2.0f;

    Body body(initialPosition, mass);

    assertVec2Equal(body.getPosition(), initialPosition);
    assertVec2Equal(body.getVelocity(), Vec2(0.0f, 0.0f));

    assert(nearlyEqual(body.getMass(), 2.0f));
    assert(nearlyEqual(body.getInverseMass(), 0.5f));

    std::cout << "[PASS] Body construction\n";
}


void testInverseMass()
{
    Body body( Vec2(0.0f, 0.0f), 4.0f );

    assert(nearlyEqual(body.getMass(), 4.0f));
    assert(nearlyEqual(body.getInverseMass(), 0.25f));

    std::cout << "[PASS] Inverse mass\n";
}


void testForceApplication()
{
    Body body(Vec2(0.0f, 0.0f), 2.0f);

    body.applyForce(Vec2(10.0f, 0.0f));

    body.Integrate(1.0f);

    // F = ma
    //
    // F = 10
    // m = 2
    //
    // a = 5
    //
    // dt = 1
    //
    // v = 0 + 5(1)
    // v = 5

    assertVec2Equal(body.getVelocity(), Vec2(5.0f, 0.0f));

    std::cout << "[PASS] Force application\n";
}


void testIntegration()
{
    Body body(Vec2(0.0f, 0.0f), 1.0f);

    body.applyForce(Vec2(10.0f, 0.0f));

    float dt = 0.1f;

    body.Integrate(dt);

    // m = 1
    // F = 10
    //
    // a = F / m
    // a = 10
    //
    // v' = v + a * dt
    // v' = 0 + 10 * 0.1
    // v' = 1
    //
    // x' = x + v' * dt
    // x' = 0 + 1 * 0.1
    // x' = 0.1

    assertVec2Equal(body.getVelocity(), Vec2(1.0f, 0.0f));
    assertVec2Equal(body.getPosition(), Vec2(0.1f, 0.0f));

    std::cout << "[PASS] Semi-implicit Euler integration\n";
}

void testForceAccumulation()
{
    Body body(Vec2(0.0f, 0.0f), 2.0f);

    body.applyForce(Vec2(10.0f, 0.0f));
    body.applyForce(Vec2(0.0f, 10.0f));

    body.Integrate(1.0f);

    // Total force:
    //
    // F = (10, 0) + (0, 10)
    // F = (10, 10)
    //
    // m = 2
    //
    // a = (5, 5)
    //
    // dt = 1
    //
    // v = (5, 5)

    assertVec2Equal(body.getVelocity(), Vec2(5.0f, 5.0f));

    std::cout << "[PASS] Force accumulation\n";
}

void testForceClearing()
{
    Body body(Vec2(0.0f, 0.0f), 1.0f);

    body.applyForce(Vec2(10.0f, 0.0f));

    body.Integrate(1.0f);

    // The force accumulator should now be cleared.
    //
    // If it wasn't cleared, the same force would be
    // applied again during the next integration.

    body.Integrate(1.0f);

    // First step:
    // v = 10
    //
    // Second step with NO remaining force:
    // v should remain 10.

    assertVec2Equal(body.getVelocity(), Vec2(10.0f, 0.0f));

    std::cout << "[PASS] Force clearing\n";
}



void testZeroForce()
{
    Body body(Vec2(5.0f, 5.0f), 2.0f);

    body.Integrate(1.0f);

    // No force means:
    //
    // F = 0
    // a = 0
    //
    // Therefore velocity and position remain unchanged.

    assertVec2Equal(body.getVelocity(), Vec2(0.0f, 0.0f));
    assertVec2Equal(body.getPosition(), Vec2(5.0f, 5.0f));

    std::cout << "[PASS] Zero force\n";
}


int main()
{
    std::cout << "=== Body Tests ===\n\n";

    testBodyConstruction();
    testInverseMass();
    testForceApplication();
    testIntegration();
    testForceAccumulation();
    testForceClearing();
    testZeroForce();

    std::cout << "\nAll Body tests passed!\n";

    return 0;
}
