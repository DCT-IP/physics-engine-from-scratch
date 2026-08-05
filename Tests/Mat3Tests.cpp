#include <iostream>
#include <cmath>
#include "../Core/Math/Mat3.h"
#include "../Core/Math/Vec3.h"
#include "../Core/Math/MathUtils.h"

using namespace Math;

#define ASSERT(expr) \
if(!(expr)) \
{ \
    std::cout << "[FAILED] " << #expr << '\n'; \
} \
else \
{ \
    std::cout << "[PASSED] " << #expr << '\n'; \
}

int main()
{
    std::cout << "========== Mat3 Tests ==========\n\n";

    // -------------------------------------------------
    // Constructors
    // -------------------------------------------------

    Mat3 zero;
    ASSERT(zero.IsZero());

    Mat3 A(
        1,2,3,
        4,5,6,
        7,8,9
    );

    // -------------------------------------------------
    // Identity
    // -------------------------------------------------

    Mat3 I = Mat3::Identity();
    ASSERT(I.IsIdentity());

    // -------------------------------------------------
    // Addition
    // -------------------------------------------------

    Mat3 B(
        9,8,7,
        6,5,4,
        3,2,1
    );

    Mat3 add = A + B;

    ASSERT(add ==
        Mat3(
            10,10,10,
            10,10,10,
            10,10,10
        ));

    // -------------------------------------------------
    // Subtraction
    // -------------------------------------------------

    Mat3 sub = A - B;

    ASSERT(sub ==
        Mat3(
            -8,-6,-4,
            -2,0,2,
            4,6,8
        ));

    // -------------------------------------------------
    // Scalar Multiply
    // -------------------------------------------------

    Mat3 mul = A * 2.0f;

    ASSERT(mul ==
        Mat3(
            2,4,6,
            8,10,12,
            14,16,18
        ));

    // -------------------------------------------------
    // Scalar Divide
    // -------------------------------------------------

    Mat3 div = mul / 2.0f;

    ASSERT(div == A);

    // -------------------------------------------------
    // Matrix Multiplication
    // -------------------------------------------------

    Mat3 C(
        1,0,0,
        0,1,0,
        0,0,1
    );

    ASSERT((A * C) == A);

    // -------------------------------------------------
    // Matrix × Vector
    // -------------------------------------------------

    Vec3 v(1,2,3);

    Vec3 r = C * v;

    ASSERT(r == v);

    // -------------------------------------------------
    // Trace
    // -------------------------------------------------

    ASSERT(Math::NearlyEqual(A.Trace(),15.0f));

    // -------------------------------------------------
    // Determinant
    // -------------------------------------------------

    Mat3 detMat(
        1,2,3,
        0,1,4,
        5,6,0
    );

    ASSERT(Math::NearlyEqual(detMat.Determinant(),1.0f));

    // -------------------------------------------------
    // Transpose
    // -------------------------------------------------

    Mat3 t = A.Transposed();

    ASSERT(t ==
        Mat3(
            1,4,7,
            2,5,8,
            3,6,9
        ));

    // -------------------------------------------------
    // Inverse
    // -------------------------------------------------

    Mat3 invSource(
        4,7,2,
        3,6,1,
        2,5,1
    );

    Mat3 inv = invSource.Inverse();

    Mat3 result = invSource * inv;

    ASSERT(result.IsIdentity());

    // -------------------------------------------------
    // Rotation
    // -------------------------------------------------

    Mat3 rot = Mat3::Rotation(Math::PI / 2.0f);

    Vec3 xAxis(1,0,1);

    Vec3 rotated = rot * xAxis;

    ASSERT(Math::NearlyEqual(rotated.x,0.0f));
    ASSERT(Math::NearlyEqual(rotated.y,1.0f));

    // -------------------------------------------------
    // Scale
    // -------------------------------------------------

    Mat3 scale = Mat3::Scale(2.0f,3.0f);

    Vec3 p(1,2,1);

    Vec3 scaled = scale * p;

    ASSERT(Math::NearlyEqual(scaled.x,2.0f));
    ASSERT(Math::NearlyEqual(scaled.y,6.0f));

    // -------------------------------------------------
    // Translation
    // -------------------------------------------------

    Mat3 trans = Mat3::Translation(5,3);

    Vec3 point(2,4,1);

    Vec3 moved = trans * point;

    ASSERT(Math::NearlyEqual(moved.x,7.0f));
    ASSERT(Math::NearlyEqual(moved.y,7.0f));

    // -------------------------------------------------
    // IsZero
    // -------------------------------------------------

    ASSERT(Mat3::Zero().IsZero());

    std::cout << "\n========== Tests Complete ==========\n";
}