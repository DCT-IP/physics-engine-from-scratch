#include <iostream>
#include <cmath>

#include "Transform2D.h"

int main()
{
    int passed = 0;
    int failed = 0;

    auto Test = [&](const char* name, bool condition)
    {
        if (condition)
        {
            std::cout << "[PASS] " << name << "\n";
            passed++;
        }
        else
        {
            std::cout << "[FAIL] " << name << "\n";
            failed++;
        }
    };

    // ==========================================================
    // Default Constructor
    // ==========================================================

    Math::Transform2D transform;

    Test(
        "Default position",
        transform.position == Math::Vec2(0.0f, 0.0f)
    );

    Test(
        "Default rotation",
        Math::NearlyEqual(transform.rotation, 0.0f)
    );

    Test(
        "Default scale",
        transform.scale == Math::Vec2(1.0f, 1.0f)
    );

    // ==========================================================
    // Parameterized Constructor
    // ==========================================================

    Math::Transform2D custom(
        Math::Vec2(5.0f, 10.0f),
        1.5f,
        Math::Vec2(2.0f, 3.0f)
    );

    Test(
        "Parameterized position",
        custom.position == Math::Vec2(5.0f, 10.0f)
    );

    Test(
        "Parameterized rotation",
        Math::NearlyEqual(custom.rotation, 1.5f)
    );

    Test(
        "Parameterized scale",
        custom.scale == Math::Vec2(2.0f, 3.0f)
    );

    // ==========================================================
    // Identity
    // ==========================================================

    Math::Transform2D identity = Math::Transform2D::Identity();

    Test(
        "Identity position",
        identity.position == Math::Vec2(0.0f, 0.0f)
    );

    Test(
        "Identity rotation",
        Math::NearlyEqual(identity.rotation, 0.0f)
    );

    Test(
        "Identity scale",
        identity.scale == Math::Vec2(1.0f, 1.0f)
    );

    // ==========================================================
    // Translation
    // ==========================================================

    transform.Translate(Math::Vec2(5.0f, 2.0f));

    Test(
        "Translate",
        transform.position == Math::Vec2(5.0f, 2.0f)
    );

    // ==========================================================
    // Rotation
    // ==========================================================

    transform.Rotate(1.0f);

    Test(
        "Rotate",
        Math::NearlyEqual(transform.rotation, 1.0f)
    );

    transform.Rotate(0.5f);

    Test(
        "Multiple rotations",
        Math::NearlyEqual(transform.rotation, 1.5f)
    );

    // ==========================================================
    // Scale
    // ==========================================================

    transform.Scale(Math::Vec2(2.0f, 3.0f));

    Test(
        "Scale",
        transform.scale == Math::Vec2(2.0f, 3.0f)
    );

    transform.Scale(Math::Vec2(2.0f, 2.0f));

    Test(
        "Multiple scales",
        transform.scale == Math::Vec2(4.0f, 6.0f)
    );

    // ==========================================================
    // Equality
    // ==========================================================

    Math::Transform2D a(
        Math::Vec2(1.0f, 2.0f),
        0.5f,
        Math::Vec2(2.0f, 2.0f)
    );

    Math::Transform2D b(
        Math::Vec2(1.0f, 2.0f),
        0.5f,
        Math::Vec2(2.0f, 2.0f)
    );

    Test(
        "Equality operator",
        a == b
    );

    b.Translate(Math::Vec2(1.0f, 0.0f));

    Test(
        "Inequality after modification",
        a != b
    );

    // ==========================================================
    // Results
    // ==========================================================

    std::cout << "\n==============================\n";
    std::cout << "Passed: " << passed << "\n";
    std::cout << "Failed: " << failed << "\n";
    std::cout << "==============================\n";

    return failed == 0 ? 0 : 1;
}