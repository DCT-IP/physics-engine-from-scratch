#include <iostream>
#include <cassert>
#include <cmath>
#include "Body.h"
#include "Gravity.h"
#include "ConstantForce.h"
#include "SemiImplicitEuler.h"

using Math::Vec2;

bool nearlyEqual(float a, float b, float epsilon = 0.0001f)
{
    return std::fabs(a - b) < epsilon;
}

void assertVec2Equal(const Vec2& actual, const Vec2& expected)
{
    if (!nearlyEqual(actual.x, expected.x) ||
        !nearlyEqual(actual.y, expected.y))
    {
        std::cerr << "Actual:   (" << actual.x
                  << ", " << actual.y << ")\n";
        std::cerr << "Expected: (" << expected.x
                  << ", " << expected.y << ")\n";
    }

    assert(nearlyEqual(actual.x, expected.x));
    assert(nearlyEqual(actual.y, expected.y));
}

void testGravity()
{
    Body body(Vec2(0.0f, 0.0f), 2.0f);
    Gravity gravity(Vec2(0.0f, -10.0f));
    SemiImplicitEuler integrator;
    gravity.apply(body);
    integrator.integrate(body, 1.0f);
    assertVec2Equal(body.getAcceleration(), Vec2(0.0f, -10.0f));
    assertVec2Equal(body.getVelocity(), Vec2(0.0f, -10.0f));
    std::cout << "[PASS] Gravity\n";
}

void testConstantForce()
{
    Body body(Vec2(0.0f, 0.0f), 2.0f);
    ConstantForce force(Vec2(10.0f, 0.0f));
    SemiImplicitEuler integrator;
    force.apply(body);
    integrator.integrate(body, 1.0f);
    assertVec2Equal(body.getAcceleration(), Vec2(5.0f, 0.0f));
    assertVec2Equal(body.getVelocity(), Vec2(5.0f, 0.0f));
    std::cout << "[PASS] Constant force\n";
}

void testGravityWithZeroMass()
{
    Body body(Vec2(0.0f, 0.0f), 0.0f);
    Gravity gravity(Vec2(0.0f, -10.0f));
    SemiImplicitEuler integrator;
    gravity.apply(body);
    integrator.integrate(body, 1.0f);
    assertVec2Equal(body.getPosition(), Vec2(0.0f, 0.0f));
    assertVec2Equal(body.getVelocity(), Vec2(0.0f, 0.0f));
    std::cout << "[PASS] Gravity with zero-mass body\n";
}
int main()
{
    std::cout << "=== Force Generator Tests ===\n\n";
    std::cout << "Running testGravity...\n";
    testGravity();
    std::cout << "Running testConstantForce...\n";
    testConstantForce();
    std::cout << "Running testGravityWithZeroMass...\n";
    testGravityWithZeroMass();
    std::cout << "\nAll Force Generator tests passed!\n";
    return 0;
}