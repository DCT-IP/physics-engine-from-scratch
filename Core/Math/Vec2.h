#pragma once

class Vec2
{
public:
    // Data Members
    float x;
    float y;

    // Constructors
    Vec2();
    Vec2(float x, float y);

    // Magnitude
    float Length() const;
    float LengthSquared() const;
    
    // Normalization
    void Normalize();
    Vec2 Normalized() const;

    // Utility
    bool IsZero() const;
    float Dot(const Vec2& other) const;
    float Distance(const Vec2& other) const;
    float DistanceSquared(const Vec2& other) const;
    Vec2 Perpendicular() const;
    Vec2 Reflect(const Vec2& normal) const;
    Vec2 Project(const Vec2& other) const;

    // Arithmetic Operators
    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& other) const;
    Vec2 operator*(float scalar) const;
    Vec2 operator/(float scalar) const;
    Vec2& operator+=(const Vec2& other);
    Vec2& operator-=(const Vec2& other);
    Vec2& operator*=(float scalar);
    Vec2& operator/=(float scalar);
    Vec2 operator-() const;

    // Comparison Operators
    bool operator==(const Vec2& other) const;
    bool operator!=(const Vec2& other) const;
};