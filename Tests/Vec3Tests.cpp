#include <cassert>
#include <cmath>
#include <iostream>

#include "../Core/Math/Vec3.h"
#include "../Core/Math/MathUtils.h"

using namespace Math;

int main()
{
    std::cout << "========== Vec3 Tests ==========\n";

    // ==========================================================
    // Constructors
    // ==========================================================

    Vec3 a;

    assert(a.x == 0.0f);
    assert(a.y == 0.0f);
    assert(a.z == 0.0f);

    Vec3 b(1.0f, 2.0f, 3.0f);

    assert(b.x == 1.0f);
    assert(b.y == 2.0f);
    assert(b.z == 3.0f);

    // ==========================================================
    // Addition & Subtraction
    // ==========================================================

    assert(b + Vec3(4, 5, 6) == Vec3(5, 7, 9));
    assert(Vec3(5, 7, 9) - b == Vec3(4, 5, 6));

    // ==========================================================
    // Scalar Multiplication & Division
    // ==========================================================

    assert(b * 2 == Vec3(2, 4, 6));
    assert(b / 2 == Vec3(0.5f, 1.0f, 1.5f));

    // ==========================================================
    // Compound Assignment Operators
    // ==========================================================

    Vec3 c(1, 1, 1);

    c += Vec3(2, 3, 4);
    assert(c == Vec3(3, 4, 5));

    c -= Vec3(1, 1, 1);
    assert(c == Vec3(2, 3, 4));

    c *= 2;
    assert(c == Vec3(4, 6, 8));

    c /= 2;
    assert(c == Vec3(2, 3, 4));

    // ==========================================================
    // Unary Operators
    // ==========================================================

    assert(-b == Vec3(-1, -2, -3));

    // ==========================================================
    // Length & LengthSquared
    // ==========================================================

    assert(std::fabs(b.Length() - std::sqrt(14.0f)) < 0.0001f);
    assert(b.LengthSquared() == 14.0f);

    // ==========================================================
    // Normalization
    // ==========================================================

    Vec3 d(3, 0, 0);
    d.Normalize();
    assert(std::fabs(d.Length() - 1.0f) < 0.0001f);

    Vec3 e(0, 4, 0);
    Vec3 f = e.Normalized();
    assert(std::fabs(f.Length() - 1.0f) < 0.0001f);

    // ==========================================================
    // Dot & Cross Products
    // ==========================================================

    assert(Vec3(1, 2, 3).Dot(Vec3(4, 5, 6)) == 32.0f);
    assert(Vec3(1, 0, 0).Cross(Vec3(0, 1, 0)) == Vec3(0, 0, 1));
    assert(Vec3(0, 1, 0).Cross(Vec3(1, 0, 0)) == Vec3(0, 0, -1));

    // ==========================================================
    // Distance & DistanceSquared
    // ==========================================================

    assert(std::fabs(Vec3(0, 0, 0).Distance(Vec3(1, 2, 2)) - 3.0f) < 0.0001f);
    assert(Vec3(0, 0, 0).DistanceSquared(Vec3(1, 2, 2)) == 9.0f);

    // ==========================================================
    // Perpendicular, Reflect, Project
    // ==========================================================

    Vec3 p1 = Vec3(1, 0, 0).Perpendicular();
    assert(Math::IsZero(p1.Dot(Vec3(1, 0, 0))));

    // Edge case: Z-axis vector
    Vec3 p2 = Vec3(0, 0, 5).Perpendicular();
    assert(!p2.IsZero());
    assert(Math::IsZero(p2.Dot(Vec3(0, 0, 5))));

    Vec3 ray(1, -1, 0);
    Vec3 normal(0, 1, 0);
    assert(ray.Reflect(normal) == Vec3(1, 1, 0));

    Vec3 v(3, 4, 0);
    Vec3 target(1, 0, 0);
    assert(v.Project(target) == Vec3(3, 0, 0));

    // ==========================================================
    // IsZero & Equality
    // ==========================================================

    assert(Vec3().IsZero());
    assert(!Vec3(1, 0, 0).IsZero());
    assert(Vec3(1, 2, 3) == Vec3(1, 2, 3));
    assert(Vec3(1, 2, 3) != Vec3(3, 2, 1));

    std::cout << "All Vec3 Tests Passed!\n";

    return 0;
}