#include "Vec3.h"
#include "MathUtils.h"
#include <cmath>

namespace Math {

Vec3::Vec3() : x(0.0f), y(0.0f), z(0.0f) {}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

float Vec3::LengthSquared() const
{
    return (x * x) + (y * y) + (z * z);
}

float Vec3::Length() const
{
    return std::sqrt(LengthSquared());
}

void Vec3::Normalize()
{
    float lenSq = LengthSquared();
    if (!Math::IsZero(lenSq))
    {
        float invLen = 1.0f / std::sqrt(lenSq);
        x *= invLen;
        y *= invLen;
        z *= invLen;
    }
}

Vec3 Vec3::Normalized() const
{
    float lenSq = LengthSquared();
    if (!Math::IsZero(lenSq))
    {
        float invLen = 1.0f / std::sqrt(lenSq);
        return Vec3(x * invLen, y * invLen, z * invLen);
    }
    return Vec3(0.0f, 0.0f, 0.0f);
}

bool Vec3::IsZero() const 
{
    return Math::IsZero(x) && Math::IsZero(y) && Math::IsZero(z); 
}

float Vec3::Dot(const Vec3& other) const
{
    return (x * other.x) + (y * other.y) + (z * other.z);
}

Vec3 Vec3::Cross(const Vec3& other) const
{
    return Vec3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

float Vec3::DistanceSquared(const Vec3& other) const 
{
    float del_x = x - other.x;
    float del_y = y - other.y;
    float del_z = z - other.z;
    return (del_x * del_x) + (del_y * del_y) + (del_z * del_z);
}

float Vec3::Distance(const Vec3& other) const
{
    return std::sqrt(DistanceSquared(other));
}

Vec3 Vec3::Perpendicular() const
{
    Vec3 axis = (Math::Abs(x) < 0.9f) ? Vec3(1.0f, 0.0f, 0.0f) : Vec3(0.0f, 1.0f, 0.0f);
    return Cross(axis).Normalized();
}

Vec3 Vec3::Reflect(const Vec3& normal) const
{
    return *this - (normal * (2.0f * this->Dot(normal)));
}

Vec3 Vec3::Project(const Vec3& other) const 
{
    float lenSq = other.LengthSquared();
    if (Math::IsZero(lenSq)) return Vec3(0.0f, 0.0f, 0.0f);
    float scalar = this->Dot(other) / lenSq;
    return other * scalar;
}

Vec3 Vec3::operator+(const Vec3& other) const 
{
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3& other) const 
{
    return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::operator*(float scalar) const 
{
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::operator/(float scalar) const 
{
    if (Math::IsZero(scalar)) return Vec3(0.0f, 0.0f, 0.0f);
    float invScalar = 1.0f / scalar; 
    return Vec3(x * invScalar, y * invScalar, z * invScalar);
}

Vec3& Vec3::operator+=(const Vec3& other) 
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& other) 
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vec3& Vec3::operator*=(float scalar) 
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

Vec3& Vec3::operator/=(float scalar) 
{
    if (Math::IsZero(scalar)) {
        x = 0.0f; y = 0.0f; z = 0.0f;
        return *this;
    }
    float invScalar = 1.0f / scalar;
    x *= invScalar;
    y *= invScalar;
    z *= invScalar;
    return *this;
}

Vec3 Vec3::operator-() const 
{
    return Vec3(-x, -y, -z);
}

bool Vec3::operator==(const Vec3& other) const 
{
    return Math::NearlyEqual(x, other.x) && 
           Math::NearlyEqual(y, other.y) && 
           Math::NearlyEqual(z, other.z);
}

bool Vec3::operator!=(const Vec3& other) const 
{
    return !(*this == other);
}

} // namespace Math