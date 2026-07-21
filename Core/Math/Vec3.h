#pragma once

namespace Math
{

class Vec3
{
public:
    float x;
    float y;
    float z;

    // Constructors
    Vec3();
    Vec3(float x, float y, float z);

    // Static Utility Vectors
    static Vec3 Zero()    { return Vec3(0.0f, 0.0f, 0.0f); }
    static Vec3 One()     { return Vec3(1.0f, 1.0f, 1.0f); }
    static Vec3 Up()      { return Vec3(0.0f, 1.0f, 0.0f); }
    static Vec3 Down()    { return Vec3(0.0f, -1.0f, 0.0f); }
    static Vec3 Left()    { return Vec3(-1.0f, 0.0f, 0.0f); }
    static Vec3 Right()   { return Vec3(1.0f, 0.0f, 0.0f); }
    static Vec3 Forward() { return Vec3(0.0f, 0.0f, 1.0f); }
    static Vec3 Back()    { return Vec3(0.0f, 0.0f, -1.0f); }

    // Length & Normalization
    float Length() const;
    float LengthSquared() const;
    void Normalize();
    Vec3 Normalized() const;

    // Vector Operations
    bool IsZero() const;
    float Dot(const Vec3& other) const;
    Vec3 Cross(const Vec3& other) const;
    float Distance(const Vec3& other) const;
    float DistanceSquared(const Vec3& other) const;
    Vec3 Perpendicular() const;
    Vec3 Reflect(const Vec3& normal) const;
    Vec3 Project(const Vec3& other) const;

    // Operators
    Vec3 operator+(const Vec3& other) const;
    Vec3 operator-(const Vec3& other) const;
    Vec3 operator*(float scalar) const;
    Vec3 operator/(float scalar) const;

    Vec3& operator+=(const Vec3& other);
    Vec3& operator-=(const Vec3& other);
    Vec3& operator*=(float scalar);
    Vec3& operator/=(float scalar);

    Vec3 operator-() const;

    bool operator==(const Vec3& other) const;
    bool operator!=(const Vec3& other) const;

    // Subscript access
    float operator[](unsigned int index) const { return (&x)[index]; }
    float& operator[](unsigned int index) { return (&x)[index]; }
};

// Enables float * Vec3 syntax
inline Vec3 operator*(float scalar, const Vec3& vec)
{
    return vec * scalar;
}

} // namespace Math