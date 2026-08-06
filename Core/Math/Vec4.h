#pragma once

namespace Math
{

class Vec4
{
public:
    float x;
    float y;
    float z;
    float w;

    // Constructors
    Vec4();
    Vec4(float x, float y, float z, float w);

    // Magnitude
    float Length() const;
    float LengthSquared() const;

    // Normalization
    void Normalize();
    Vec4 Normalized() const;

    // Utility
    bool IsZero() const;
    float Dot(const Vec4& other) const;
    float Distance(const Vec4& other) const;
    float DistanceSquared(const Vec4& other) const;

    // Operators
    Vec4 operator+(const Vec4& other) const;
    Vec4 operator-(const Vec4& other) const;

    Vec4 operator*(float scalar) const;
    Vec4 operator/(float scalar) const;

    Vec4& operator+=(const Vec4& other);
    Vec4& operator-=(const Vec4& other);

    Vec4& operator*=(float scalar);
    Vec4& operator/=(float scalar);

    Vec4 operator-() const;

    bool operator==(const Vec4& other) const;
    bool operator!=(const Vec4& other) const;
};

}