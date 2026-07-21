#pragma once

namespace Math
{

class Vec2
{
public:
    float x;
    float y;

    // Constructors
    Vec2();
    Vec2(float x, float y);

    // Static Utility Vectors
    static Vec2 Zero()  { return Vec2(0.0f, 0.0f); }
    static Vec2 One()   { return Vec2(1.0f, 1.0f); }
    static Vec2 Up()    { return Vec2(0.0f, 1.0f); }
    static Vec2 Down()  { return Vec2(0.0f, -1.0f); }
    static Vec2 Left()  { return Vec2(-1.0f, 0.0f); }
    static Vec2 Right() { return Vec2(1.0f, 0.0f); }

    // Length & Normalization
    float Length() const;
    float LengthSquared() const;
    void Normalize();
    Vec2 Normalized() const;

    // Vector Operations
    bool IsZero() const;
    float Dot(const Vec2& other) const;
    float Cross(const Vec2& other) const;
    float Distance(const Vec2& other) const;
    float DistanceSquared(const Vec2& other) const;
    Vec2 Perpendicular() const;
    Vec2 Reflect(const Vec2& normal) const;
    Vec2 Project(const Vec2& other) const;

    // Operators
    Vec2 operator+(const Vec2& other) const;
    Vec2 operator-(const Vec2& other) const;
    Vec2 operator*(float scalar) const;
    Vec2 operator/(float scalar) const;

    Vec2& operator+=(const Vec2& other);
    Vec2& operator-=(const Vec2& other);
    Vec2& operator*=(float scalar);
    Vec2& operator/=(float scalar);

    Vec2 operator-() const;

    bool operator==(const Vec2& other) const;
    bool operator!=(const Vec2& other) const;

    // Subscript access
    float operator[](unsigned int index) const { return (&x)[index]; }
    float& operator[](unsigned int index) { return (&x)[index]; }
};

// Enables float * Vec2 syntax
inline Vec2 operator*(float scalar, const Vec2& vec)
{
    return vec * scalar;
}

} // namespace Math