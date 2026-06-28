#include "Vec2.h"
#include <cmath> // Required for sqrt

Vec2::Vec2() : x(0.0f), y(0.0f) {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}


float Vec2::LengthSquared() const 
{
    return (x * x) + (y * y);
}

float Vec2::Length() const 
{
    return std::sqrt(LengthSquared());
}


void Vec2::Normalize() 
{
    float len = Length();
    if (len > 0.0f) 
    {
        x /= len;
        y /= len;
    }
}

Vec2 Vec2::Normalized() const 
{
    float len = Length();
    if (len > 0.0f) 
    {
        return Vec2(x / len, y / len);
    }
    return Vec2(0.0f, 0.0f);
}

bool Vec2::IsZero() const 
{
    return x == 0.0f && y == 0.0f;
}

float Vec2::Dot(const Vec2& other) const 
{
    return (x * other.x) + (y * other.y);
}

float Vec2::DistanceSquared(const Vec2& other) const 
{
    float dx = x - other.x;
    float dy = y - other.y;
    return (dx * dx) + (dy * dy);
}

float Vec2::Distance(const Vec2& other) const 
{
    return std::sqrt(DistanceSquared(other));
}

Vec2 Vec2::Perpendicular() const 
{
    return Vec2(-y, x);
}

Vec2 Vec2::Reflect(const Vec2& normal) const 
{
    return *this - (normal * (2.0f * this->Dot(normal)));
}

Vec2 Vec2::Project(const Vec2& other) const 
{
    float lenSq = other.LengthSquared();
    if (lenSq == 0.0f) return Vec2(0.0f, 0.0f);
    
    float scalar = this->Dot(other) / lenSq;
    return other * scalar;
}

Vec2 Vec2::operator+(const Vec2& other) const 
{
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const 
{
    return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(float scalar) const 
{
    return Vec2(x * scalar, y * scalar);
}

Vec2 Vec2::operator/(float scalar) const 
{
    float invScalar = 1.0f / scalar; 
    return Vec2(x * invScalar, y * invScalar);
}

Vec2& Vec2::operator+=(const Vec2& other) 
{
    x += other.x;
    y += other.y;
    return *this;
}

Vec2& Vec2::operator-=(const Vec2& other) 
{
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2& Vec2::operator*=(float scalar) 
{
    x *= scalar;
    y *= scalar;
    return *this;
}

Vec2& Vec2::operator/=(float scalar) 
{
    float invScalar = 1.0f / scalar;
    x *= invScalar;
    y *= invScalar;
    return *this;
}

Vec2 Vec2::operator-() const 
{
    return Vec2(-x, -y);
}


bool Vec2::operator==(const Vec2& other) const 
{
    return (x == other.x) && (y == other.y);
}

bool Vec2::operator!=(const Vec2& other) const 
{
    return !(*this == other);
}