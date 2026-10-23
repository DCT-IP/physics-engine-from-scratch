#include <iostream>
#include <iomanip>
#include <memory>

#include "../Core/Math/Vec2.h"
#include "../Core/Math/Mat2.h"
#include "../Core/Math/MathUtils.h"
#include "../Core/Math/Vec3.h"
#include "../Core/Math/Mat3.h"
#include "../Core/Math/Vec4.h"
#include "../Core/Math/Mat4.h"
#include "../Core/Math/Transform2D.h"
#include "../Core/Math/Transform3D.h"
#include "../Core/Math/Quaternion.h"

#include "../Core/Time/Time.h"

#include "../Physics/Body.h"
#include "../Physics/Gravity.h"
#include "../Physics/ConstantForce.h"
#include "../Physics/FixedTimestep.h"
#include "../Physics/SimulationWorld.h"

using namespace Math;

// --------------------------------------------------
// Helpers
// --------------------------------------------------

void printVec2(const Vec2& v)
{
    std::cout << "(" << v.x << ", " << v.y << ")";
}

void printVec3(const Vec3& v)
{
    std::cout << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

void printVec4(const Vec4& v)
{
    std::cout << "(" << v.x << ", " << v.y
              << ", " << v.z << ", " << v.w << ")";
}

void printSection(const char* title)
{
    std::cout << "\n========================================\n"
              << title
              << "\n========================================\n";
}

// --------------------------------------------------
// Math demonstrations
// --------------------------------------------------

void demoMath()
{
    printSection("Math Utilities");

    std::cout << "PI: " << PI << '\n';
    std::cout << "Clamp(15, 0, 10): "
              << Clamp(15.0f, 0.0f, 10.0f) << '\n';
    std::cout << "Lerp(0, 100, 0.25): "
              << Lerp(0.0f, 100.0f, 0.25f) << '\n';
    std::cout << "90 degrees in radians: "
              << DegreesToRadians(90.0f) << '\n';

    printSection("Vec2 and Mat2");

    Vec2 a(2.0f, 3.0f);
    Vec2 b(4.0f, 1.0f);

    std::cout << "A = ";
    printVec2(a);
    std::cout << "\nB = ";
    printVec2(b);
    std::cout << "\nA + B = ";
    printVec2(a + b);
    std::cout << '\n';

    Mat2 matrix(
        1.0f, 2.0f,
        3.0f, 4.0f
    );

    std::cout << "Matrix determinant: "
              << matrix.Determinant() << '\n';
    std::cout << "Matrix trace: "
              << matrix.Trace() << '\n';
    std::cout << "Matrix * A = ";
    printVec2(matrix * a);
    std::cout << '\n';

    printSection("Vec3 and Mat3");

    Vec3 v3a(1.0f, 2.0f, 3.0f);
    Vec3 v3b(4.0f, 5.0f, 6.0f);

    std::cout << "A = ";
    printVec3(v3a);
    std::cout << "\nB = ";
    printVec3(v3b);
    std::cout << "\nDot product: "
              << v3a.Dot(v3b) << '\n';
    std::cout << "Cross product: ";
    printVec3(v3a.Cross(v3b));
    std::cout << '\n';

    Mat3 rotation = Mat3::Rotation(HALF_PI);
    Vec3 point(1.0f, 0.0f, 1.0f);

    std::cout << "2D rotation matrix applied to point: ";
    printVec3(rotation * point);
    std::cout << '\n';

    printSection("Vec4 and Mat4");

    Vec4 v4(1.0f, 2.0f, 3.0f, 1.0f);
    Mat4 identity = Mat4::Identity();

    std::cout << "Vector: ";
    printVec4(v4);
    std::cout << "\nIdentity * vector: ";
    printVec4(identity * v4);
    std::cout << '\n';

    printSection("Transforms");

    Transform2D transform2D;
    transform2D.Translate(Vec2(5.0f, 3.0f));
    transform2D.Rotate(HALF_PI);
    transform2D.Scale(Vec2(2.0f, 2.0f));

    std::cout << "Transform2D position: ";
    printVec2(transform2D.position);
    std::cout << "\nRotation: "
              << transform2D.rotation << " radians\n";
    std::cout << "Scale: ";
    printVec2(transform2D.scale);
    std::cout << '\n';

    Transform3D transform3D(
        Vec3(10.0f, 20.0f, 30.0f),
        Vec3(2.0f, 2.0f, 2.0f)
    );

    Vec3 originalPoint(1.0f, 2.0f, 3.0f);

    std::cout << "Original 3D point: ";
    printVec3(originalPoint);
    std::cout << "\nTransformed point: ";
    printVec3(transform3D.TransformPoint(originalPoint));
    std::cout << '\n';

    printSection("Quaternion");

    Quaternion q = Quaternion::FromAxisAngle(
        Vec3(0.0f, 0.0f, 1.0f),
        HALF_PI
    );

    Vec3 originalVector(1.0f, 0.0f, 0.0f);

    std::cout << "Original vector: ";
    printVec3(originalVector);
    std::cout << "\nRotated vector: ";
    printVec3(q.Rotate(originalVector));
    std::cout << '\n';
}

// --------------------------------------------------
// Time demonstration
// --------------------------------------------------

void demoTime()
{
    printSection("Time");

    Time timer;

    std::cout << "Initial elapsed time: "
              << timer.getElapsedTime() << " seconds\n";

    timer.tick();

    std::cout << "Delta time: "
              << timer.getDeltaTime() << " seconds\n";
    std::cout << "Elapsed time: "
              << timer.getElapsedTime() << " seconds\n";

    timer.reset();

    std::cout << "Elapsed time after reset: "
              << timer.getElapsedTime() << " seconds\n";
}

// --------------------------------------------------
// Fixed timestep demonstration
// --------------------------------------------------

void demoFixedTimestep()
{
    printSection("Fixed Timestep");

    FixedTimestep timestep(1.0f / 60.0f);

    std::size_t totalSteps = 0;

    // Simulate three frames, each lasting 1/30 second.
    for (int frame = 1; frame <= 3; ++frame) {
        const std::size_t steps = timestep.advance(
            1.0f / 30.0f,
            [](float dt) {
                // A physics update would execute here.
                (void)dt;
            }
        );

        totalSteps += steps;

        std::cout << "Frame " << frame
                  << ": physics steps = " << steps << '\n';
    }

    std::cout << "Total physics steps: "
              << totalSteps << '\n';
    std::cout << "Remaining accumulated time: "
              << timestep.getAccumulator() << " seconds\n";
}

// --------------------------------------------------
// Simulation world demonstration
// --------------------------------------------------

void demoSimulationWorld()
{
    printSection("Simulation World");

    constexpr float fixedDt = 1.0f / 60.0f;

    SimulationWorld world(fixedDt, 8);

    Body& fallingBody = world.addBody(
        std::make_unique<Body>(
            Vec2(0.0f, 10.0f),
            2.0f
        )
    );

    Body& pushedBody = world.addBody(
        std::make_unique<Body>(
            Vec2(5.0f, 0.0f),
            2.0f
        )
    );

    world.addForceGenerator(
        fallingBody,
        std::make_unique<Gravity>(
            Vec2(0.0f, -9.81f)
        )
    );

    world.addForceGenerator(
        pushedBody,
        std::make_unique<ConstantForce>(
            Vec2(10.0f, 0.0f)
        )
    );

    std::cout << "Bodies in world: "
              << world.getBodyCount() << '\n';
    std::cout << "Fixed timestep: "
              << world.getFixedDeltaTime() << " seconds\n";

    // Simulate 5 frames at approximately 30 FPS.
    constexpr float frameDt = 1.0f / 30.0f;

    for (int frame = 1; frame <= 5; ++frame) {
        const std::size_t steps = world.advance(frameDt);

        std::cout << "\nFrame " << frame
                  << " | physics steps: " << steps << '\n';

        std::cout << "Falling body position: ";
        printVec2(fallingBody.getPosition());
        std::cout << " | velocity: ";
        printVec2(fallingBody.getVelocity());
        std::cout << '\n';

        std::cout << "Pushed body position: ";
        printVec2(pushedBody.getPosition());
        std::cout << " | velocity: ";
        printVec2(pushedBody.getVelocity());
        std::cout << '\n';
    }
}

// --------------------------------------------------
// Main
// --------------------------------------------------

int main()
{
    std::cout << std::fixed << std::setprecision(4);

    demoMath();
    demoTime();
    demoFixedTimestep();
    demoSimulationWorld();

    printSection("Demo Complete");

    return 0;
}
