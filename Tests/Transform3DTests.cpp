#include "Transform3D.h"
#include <cassert>
#include <cmath>
#include <iostream>

bool NearlyEqual(float a, float b, float epsilon = 0.0001f)
{
    return std::fabs(a - b) < epsilon;
}

void TestDefaultConstructor()
{
    Math::Transform3D transform;

    assert(NearlyEqual(transform.GetPosition().x, 0.0f));
    assert(NearlyEqual(transform.GetPosition().y, 0.0f));
    assert(NearlyEqual(transform.GetPosition().z, 0.0f));

    assert(NearlyEqual(transform.GetScale().x, 1.0f));
    assert(NearlyEqual(transform.GetScale().y, 1.0f));
    assert(NearlyEqual(transform.GetScale().z, 1.0f));
}

void TestConstructor()
{
    Math::Transform3D transform(
        Math::Vec3(1.0f, 2.0f, 3.0f),
        Math::Vec3(2.0f, 3.0f, 4.0f)
    );

    assert(NearlyEqual(transform.GetPosition().x, 1.0f));
    assert(NearlyEqual(transform.GetPosition().y, 2.0f));
    assert(NearlyEqual(transform.GetPosition().z, 3.0f));

    assert(NearlyEqual(transform.GetScale().x, 2.0f));
    assert(NearlyEqual(transform.GetScale().y, 3.0f));
    assert(NearlyEqual(transform.GetScale().z, 4.0f));
}

void TestTranslation()
{
    Math::Transform3D transform;

    transform.Translate(Math::Vec3(5.0f, 10.0f, 15.0f));

    assert(NearlyEqual(transform.GetPosition().x, 5.0f));
    assert(NearlyEqual(transform.GetPosition().y, 10.0f));
    assert(NearlyEqual(transform.GetPosition().z, 15.0f));
}

void TestScaling()
{
    Math::Transform3D transform;

    transform.Scale(Math::Vec3(2.0f, 3.0f, 4.0f));

    assert(NearlyEqual(transform.GetScale().x, 2.0f));
    assert(NearlyEqual(transform.GetScale().y, 3.0f));
    assert(NearlyEqual(transform.GetScale().z, 4.0f));
}

void TestTransformPoint()
{
    Math::Transform3D transform(
        Math::Vec3(10.0f, 20.0f, 30.0f),
        Math::Vec3(2.0f, 2.0f, 2.0f)
    );

    Math::Vec3 point(1.0f, 2.0f, 3.0f);

    Math::Vec3 result = transform.TransformPoint(point);

    assert(NearlyEqual(result.x, 12.0f));
    assert(NearlyEqual(result.y, 24.0f));
    assert(NearlyEqual(result.z, 36.0f));
}

int main()
{
    TestDefaultConstructor();
    TestConstructor();
    TestTranslation();
    TestScaling();
    TestTransformPoint();

    std::cout << "Transform3D tests passed.\n";

    return 0;
}