#include "Quaternion.h"
#include "MathUtils.h"

#include <cmath>

namespace Math
{

Quaternion::Quaternion()
    : w(1.0f), x(0.0f), y(0.0f), z(0.0f)
{
}

Quaternion::Quaternion(float w, float x, float y, float z)
    : w(w), x(x), y(y), z(z)
{
}

Quaternion Quaternion::Identity()
{
    return Quaternion(
        1.0f,
        0.0f,
        0.0f,
        0.0f
    );
}

Quaternion Quaternion::FromAxisAngle(
    const Vec3& axis,
    float angleRadians
)
{
    Vec3 normalizedAxis = axis.Normalized();

    float halfAngle = angleRadians * 0.5f;

    float sinHalf = std::sin(halfAngle);
    float cosHalf = std::cos(halfAngle);

    return Quaternion(
        cosHalf,
        normalizedAxis.x * sinHalf,
        normalizedAxis.y * sinHalf,
        normalizedAxis.z * sinHalf
    );
}

float Quaternion::LengthSquared() const
{
    return
        w * w +
        x * x +
        y * y +
        z * z;
}

float Quaternion::Length() const
{
    return std::sqrt(LengthSquared());
}

void Quaternion::Normalize()
{
    float length = Length();

    if (!Math::IsZero(length))
    {
        w /= length;
        x /= length;
        y /= length;
        z /= length;
    }
}

Quaternion Quaternion::Normalized() const
{
    float length = Length();

    if (!Math::IsZero(length))
    {
        return Quaternion(
            w / length,
            x / length,
            y / length,
            z / length
        );
    }

    return Quaternion::Identity();
}

Quaternion Quaternion::Conjugate() const
{
    return Quaternion(
        w,
        -x,
        -y,
        -z
    );
}

Quaternion Quaternion::Inverse() const
{
    float lengthSquared = LengthSquared();

    if (Math::IsZero(lengthSquared))
    {
        return Quaternion::Identity();
    }

    return Conjugate() / lengthSquared;
}

float Quaternion::Dot(const Quaternion& other) const
{
    return
        w * other.w +
        x * other.x +
        y * other.y +
        z * other.z;
}

Vec3 Quaternion::Rotate(const Vec3& vector) const
{
    Quaternion vectorQuaternion(
        0.0f,
        vector.x,
        vector.y,
        vector.z
    );

    Quaternion result =
        (*this) * vectorQuaternion * this->Inverse();

    return Vec3(
        result.x,
        result.y,
        result.z
    );
}

Mat4 Quaternion::ToMatrix() const
{
    Quaternion q = Normalized();

    float xx = q.x * q.x;
    float yy = q.y * q.y;
    float zz = q.z * q.z;

    float xy = q.x * q.y;
    float xz = q.x * q.z;
    float yz = q.y * q.z;

    float wx = q.w * q.x;
    float wy = q.w * q.y;
    float wz = q.w * q.z;

    return Mat4(
        1.0f - 2.0f * (yy + zz),
        2.0f * (xy - wz),
        2.0f * (xz + wy),
        0.0f,

        2.0f * (xy + wz),
        1.0f - 2.0f * (xx + zz),
        2.0f * (yz - wx),
        0.0f,

        2.0f * (xz - wy),
        2.0f * (yz + wx),
        1.0f - 2.0f * (xx + yy),
        0.0f,

        0.0f,
        0.0f,
        0.0f,
        1.0f
    );
}

Quaternion Quaternion::operator+(
    const Quaternion& other
) const
{
    return Quaternion(
        w + other.w,
        x + other.x,
        y + other.y,
        z + other.z
    );
}

Quaternion Quaternion::operator-(
    const Quaternion& other
) const
{
    return Quaternion(
        w - other.w,
        x - other.x,
        y - other.y,
        z - other.z
    );
}

Quaternion Quaternion::operator*(
    const Quaternion& other
) const
{
    return Quaternion(
        w * other.w - x * other.x - y * other.y - z * other.z,

        w * other.x + x * other.w + y * other.z - z * other.y,

        w * other.y - x * other.z + y * other.w + z * other.x,

        w * other.z + x * other.y - y * other.x + z * other.w
    );
}

Quaternion Quaternion::operator*(float scalar) const
{
    return Quaternion(
        w * scalar,
        x * scalar,
        y * scalar,
        z * scalar
    );
}

Quaternion Quaternion::operator/(float scalar) const
{
    float inverseScalar = 1.0f / scalar;

    return Quaternion(
        w * inverseScalar,
        x * inverseScalar,
        y * inverseScalar,
        z * inverseScalar
    );
}

Quaternion& Quaternion::operator+=(
    const Quaternion& other
)
{
    w += other.w;
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Quaternion& Quaternion::operator-=(
    const Quaternion& other
)
{
    w -= other.w;
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
}

Quaternion& Quaternion::operator*=(
    const Quaternion& other
)
{
    *this = *this * other;
    return *this;
}

Quaternion& Quaternion::operator*=(float scalar)
{
    w *= scalar;
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

Quaternion& Quaternion::operator/=(float scalar)
{
    float inverseScalar = 1.0f / scalar;

    w *= inverseScalar;
    x *= inverseScalar;
    y *= inverseScalar;
    z *= inverseScalar;

    return *this;
}

Quaternion Quaternion::operator-() const
{
    return Quaternion(
        -w,
        -x,
        -y,
        -z
    );
}

bool Quaternion::operator==(
    const Quaternion& other
) const
{
    return
        Math::NearlyEqual(w, other.w) &&
        Math::NearlyEqual(x, other.x) &&
        Math::NearlyEqual(y, other.y) &&
        Math::NearlyEqual(z, other.z);
}

bool Quaternion::operator!=(
    const Quaternion& other
) const
{
    return !(*this == other);
}

}