#include "Vec4.h"
#include "MathUtils.h"

#include <cmath>

namespace Math
{

Vec4::Vec4()
    : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{
}

Vec4::Vec4(float x, float y, float z, float w)
    : x(x), y(y), z(z), w(w)
{
}

float Vec4::LengthSquared() const
{
    return x*x + y*y + z*z + w*w;
}

float Vec4::Length() const
{
    return std::sqrt(LengthSquared());
}

void Vec4::Normalize()
{
    float len = Length();

    // Use Math::IsZero to call the float helper, not Vec4::IsZero()
    if (!Math::IsZero(len))
    {
        x /= len;
        y /= len;
        z /= len;
        w /= len;
    }
}

Vec4 Vec4::Normalized() const
{
    float len = Length();

    // Use Math::IsZero to call the float helper, not Vec4::IsZero()
    if (Math::IsZero(len))
        return Vec4();

    return Vec4(
        x / len,
        y / len,
        z / len,
        w / len
    );
}

bool Vec4::IsZero() const
{
    // Explicitly scope Math::IsZero for each float component
    return Math::IsZero(x)
        && Math::IsZero(y)
        && Math::IsZero(z)
        && Math::IsZero(w);
}

float Vec4::Dot(const Vec4& other) const
{
    return x*other.x
         + y*other.y
         + z*other.z
         + w*other.w;
}

float Vec4::DistanceSquared(const Vec4& other) const
{
    float dx = x - other.x;
    float dy = y - other.y;
    float dz = z - other.z;
    float dw = w - other.w;

    return dx*dx + dy*dy + dz*dz + dw*dw;
}

float Vec4::Distance(const Vec4& other) const
{
    return std::sqrt(DistanceSquared(other));
}

Vec4 Vec4::operator+(const Vec4& other) const
{
    return Vec4(
        x + other.x,
        y + other.y,
        z + other.z,
        w + other.w
    );
}

Vec4 Vec4::operator-(const Vec4& other) const
{
    return Vec4(
        x - other.x,
        y - other.y,
        z - other.z,
        w - other.w
    );
}

Vec4 Vec4::operator*(float scalar) const
{
    return Vec4(
        x * scalar,
        y * scalar,
        z * scalar,
        w * scalar
    );
}

Vec4 Vec4::operator/(float scalar) const
{
    float inv = 1.0f / scalar;

    return Vec4(
        x * inv,
        y * inv,
        z * inv,
        w * inv
    );
}

Vec4& Vec4::operator+=(const Vec4& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

Vec4& Vec4::operator-=(const Vec4& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

Vec4& Vec4::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;
    return *this;
}

Vec4& Vec4::operator/=(float scalar)
{
    float inv = 1.0f / scalar;

    x *= inv;
    y *= inv;
    z *= inv;
    w *= inv;

    return *this;
}

Vec4 Vec4::operator-() const
{
    return Vec4(
        -x,
        -y,
        -z,
        -w
    );
}

bool Vec4::operator==(const Vec4& other) const
{
    return Math::NearlyEqual(x, other.x)
        && Math::NearlyEqual(y, other.y)
        && Math::NearlyEqual(z, other.z)
        && Math::NearlyEqual(w, other.w);
}

bool Vec4::operator!=(const Vec4& other) const
{
    return !(*this == other);
}

} // namespace Math