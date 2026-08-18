#include "Quaternion.h"

#include <cassert>
#include <cmath>
#include <iostream>

bool NearlyEqual(float a, float b, float epsilon = 0.0001f)
{
    return std::fabs(a - b) < epsilon;
}

void TestDefaultConstructor()
{
    Math::Quaternion q;

    assert(NearlyEqual(q.w, 1.0f));
    assert(NearlyEqual(q.x, 0.0f));
    assert(NearlyEqual(q.y, 0.0f));
    assert(NearlyEqual(q.z, 0.0f));
}

void TestIdentity()
{
    Math::Quaternion q = Math::Quaternion::Identity();

    assert(q == Math::Quaternion(1.0f, 0.0f, 0.0f, 0.0f));
}

void TestLength()
{
    Math::Quaternion q(
        1.0f,
        2.0f,
        3.0f,
        4.0f
    );

    assert(NearlyEqual(
        q.LengthSquared(),
        30.0f
    ));

    assert(NearlyEqual(
        q.Length(),
        std::sqrt(30.0f)
    ));
}

void TestNormalization()
{
    Math::Quaternion q(
        2.0f,
        0.0f,
        0.0f,
        0.0f
    );

    q.Normalize();

    assert(NearlyEqual(q.w, 1.0f));
    assert(NearlyEqual(q.Length(), 1.0f));
}

void TestConjugate()
{
    Math::Quaternion q(
        1.0f,
        2.0f,
        3.0f,
        4.0f
    );

    Math::Quaternion result = q.Conjugate();

    assert(NearlyEqual(result.w, 1.0f));
    assert(NearlyEqual(result.x, -2.0f));
    assert(NearlyEqual(result.y, -3.0f));
    assert(NearlyEqual(result.z, -4.0f));
}

void TestInverse()
{
    Math::Quaternion q =
        Math::Quaternion::FromAxisAngle(
            Math::Vec3(0.0f, 0.0f, 1.0f),
            1.0f
        );

    Math::Quaternion result = q * q.Inverse();

    assert(NearlyEqual(result.w, 1.0f));
    assert(NearlyEqual(result.x, 0.0f));
    assert(NearlyEqual(result.y, 0.0f));
    assert(NearlyEqual(result.z, 0.0f));
}

void TestAxisAngle()
{
    Math::Quaternion q =
        Math::Quaternion::FromAxisAngle(
            Math::Vec3(0.0f, 0.0f, 1.0f),
            0.0f
        );

    assert(NearlyEqual(q.w, 1.0f));
    assert(NearlyEqual(q.x, 0.0f));
    assert(NearlyEqual(q.y, 0.0f));
    assert(NearlyEqual(q.z, 0.0f));
}

void TestRotation()
{
    Math::Quaternion rotation =
        Math::Quaternion::FromAxisAngle(
            Math::Vec3(0.0f, 0.0f, 1.0f),
            static_cast<float>(M_PI) / 2.0f
        );

    Math::Vec3 vector(1.0f, 0.0f, 0.0f);

    Math::Vec3 result = rotation.Rotate(vector);

    assert(NearlyEqual(result.x, 0.0f));
    assert(NearlyEqual(result.y, 1.0f));
    assert(NearlyEqual(result.z, 0.0f));
}

void TestMultiplication()
{
    Math::Quaternion identity =
        Math::Quaternion::Identity();

    Math::Quaternion q(
        1.0f,
        2.0f,
        3.0f,
        4.0f
    );

    assert(identity * q == q);
    assert(q * identity == q);
}

void TestDot()
{
    Math::Quaternion a(
        1.0f,
        2.0f,
        3.0f,
        4.0f
    );

    Math::Quaternion b(
        5.0f,
        6.0f,
        7.0f,
        8.0f
    );

    assert(NearlyEqual(
        a.Dot(b),
        70.0f
    ));
}

int main()
{
    TestDefaultConstructor();
    TestIdentity();
    TestLength();
    TestNormalization();
    TestConjugate();
    TestInverse();
    TestAxisAngle();
    TestRotation();
    TestMultiplication();
    TestDot();

    std::cout << "Quaternion tests passed.\n";

    return 0;
}