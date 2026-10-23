
#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>
#include <limits>

#include "Body.h"

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

void testBodyConstruction()
{
    Vec2 initialPosition(5.0f, 10.0f);
    Body body(initialPosition, 2.0f);

    assertVec2Equal(body.getPosition(), initialPosition);
    assertVec2Equal(body.getVelocity(), Vec2(0.0f, 0.0f));
    assertVec2Equal(body.getAcceleration(), Vec2(0.0f, 0.0f));

    assert(nearlyEqual(body.getMass(), 2.0f));
    assert(nearlyEqual(body.getInverseMass(), 0.5f));

    std::cout << "[PASS] Body construction\n";
}

void testInverseMass()
{
    Body body(Vec2(0.0f, 0.0f), 4.0f);

    assert(nearlyEqual(body.getMass(), 4.0f));
    assert(nearlyEqual(body.getInverseMass(), 0.25f));

    std::cout << "[PASS] Inverse mass\n";
}

void testZeroMass()
{
    Body body(Vec2(2.0f, 3.0f), 0.0f);

    assert(nearlyEqual(body.getMass(), 0.0f));
    assert(nearlyEqual(body.getInverseMass(), 0.0f));

    std::cout << "[PASS] Zero mass is immovable\n";
}

void testNegativeMassRejected()
{
    bool threw = false;

    try {
        Body body(Vec2(0.0f, 0.0f), -1.0f);
    }
    catch (const std::invalid_argument&) {
        threw = true;
    }

    assert(threw);

    std::cout << "[PASS] Negative mass rejected\n";
}

void testNonFiniteMassRejected()
{
    bool threwInfinity = false;
    bool threwNaN = false;

    try {
        Body body(
            Vec2(0.0f, 0.0f),
            std::numeric_limits<float>::infinity()
        );
    }
    catch (const std::invalid_argument&) {
        threwInfinity = true;
    }

    try {
        Body body(
            Vec2(0.0f, 0.0f),
            std::numeric_limits<float>::quiet_NaN()
        );
    }
    catch (const std::invalid_argument&) {
        threwNaN = true;
    }

    assert(threwInfinity);
    assert(threwNaN);

    std::cout << "[PASS] Non-finite mass rejected\n";
}

void testInitialAcceleration()
{
    Body body(Vec2(0.0f, 0.0f), 2.0f);

    assertVec2Equal(
        body.getAcceleration(),
        Vec2(0.0f, 0.0f)
    );

    std::cout << "[PASS] Initial acceleration\n";
}

int main()
{
    std::cout << "=== Body Tests ===\n\n";

    testBodyConstruction();
    testInverseMass();
    testZeroMass();
    testNegativeMassRejected();
    testNonFiniteMassRejected();
    testInitialAcceleration();

    std::cout << "\nAll Body tests passed!\n";

    return 0;
}
