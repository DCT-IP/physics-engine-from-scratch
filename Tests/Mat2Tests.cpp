#include <cassert>
#include <cmath>
#include <iostream>

#include "../Core/Math/Mat2.h"

using namespace Math;

int main()
{
    std::cout << "========== Mat2 Tests ==========\n";

    // ==========================================================
    // Constructors
    // ==========================================================

    Mat2 A;

    assert(A.m00 == 0.0f);
    assert(A.m01 == 0.0f);
    assert(A.m10 == 0.0f);
    assert(A.m11 == 0.0f);

    Mat2 B(1, 2,
           3, 4);

    assert(B.m00 == 1.0f);
    assert(B.m01 == 2.0f);
    assert(B.m10 == 3.0f);
    assert(B.m11 == 4.0f);

    // ==========================================================
    // Identity & Zero
    // ==========================================================

    Mat2 I = Mat2::Identity();
    assert(I == Mat2(1, 0,
                     0, 1));

    Mat2 Z = Mat2::Zero();
    assert(Z == Mat2(0, 0,
                     0, 0));

    // ==========================================================
    // Addition & Subtraction
    // ==========================================================

    Mat2 C = B + B;
    assert(C == Mat2(2, 4,
                     6, 8));

    C = B - Mat2(1, 1,
                 1, 1);
    assert(C == Mat2(0, 1,
                     2, 3));

    // ==========================================================
    // Scalar Operations
    // ==========================================================

    C = B * 2.0f;
    assert(C == Mat2(2, 4,
                     6, 8));

    C /= 2.0f;
    assert(C == B);

    // ==========================================================
    // Compound Operators
    // ==========================================================

    C = B;
    C += B;
    assert(C == Mat2(2, 4, 6, 8));

    C -= B;
    assert(C == B);

    C *= 3.0f;
    assert(C == Mat2(3, 6, 9, 12));

    C /= 3.0f;
    assert(C == B);

    // ==========================================================
    // Matrix Multiplication & Matrix x Vector
    // ==========================================================

    Mat2 D(5, 6,
           7, 8);

    C = B * D;
    assert(C == Mat2(19, 22,
                     43, 50));

    Vec2 V(2, 3);
    Vec2 R = B * V;
    assert(R == Vec2(8, 18));

    // ==========================================================
    // Determinant, Trace, Transpose
    // ==========================================================

    assert(B.Determinant() == -2.0f);
    assert(B.Trace() == 5.0f);

    C = B.Transposed();
    assert(C == Mat2(1, 3,
                     2, 4));

    Mat2 E = B;
    E.Transpose();
    assert(E == Mat2(1, 3,
                     2, 4));

    // ==========================================================
    // Inverse & Invert
    // ==========================================================

    Mat2 Inv = B.Inverse();
    assert(std::fabs(Inv.m00 - (-2.0f)) < 0.0001f);
    assert(std::fabs(Inv.m01 - ( 1.0f)) < 0.0001f);
    assert(std::fabs(Inv.m10 - ( 1.5f)) < 0.0001f);
    assert(std::fabs(Inv.m11 - (-0.5f)) < 0.0001f);

    E = B;
    assert(E.Invert());
    assert(std::fabs(E.m00 - (-2.0f)) < 0.0001f);
    assert(std::fabs(E.m01 - ( 1.0f)) < 0.0001f);
    assert(std::fabs(E.m10 - ( 1.5f)) < 0.0001f);
    assert(std::fabs(E.m11 - (-0.5f)) < 0.0001f);

    // Edge case: M * M^-1 = Identity
    assert(B * B.Inverse() == Mat2::Identity());

    // Edge case: Non-invertible matrix
    Mat2 Singular(1, 2, 
                 2, 4);
    assert(!Singular.Invert());

    // ==========================================================
    // Checks & Equality
    // ==========================================================

    assert(I.IsIdentity());
    assert(Z.IsZero());
    assert(B == B);
    assert(B != D);

    std::cout << "All Mat2 Tests Passed!\n";

    return 0;
}