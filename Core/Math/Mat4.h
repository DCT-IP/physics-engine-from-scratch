#pragma once

#include "Vec4.h"

namespace Math
{

class Mat4
{
public:

    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;

    // Constructors
    Mat4();
    Mat4(
        float m00,float m01,float m02,float m03,
        float m10,float m11,float m12,float m13,
        float m20,float m21,float m22,float m23,
        float m30,float m31,float m32,float m33
    );

    static Mat4 Identity();

    // Arithmetic
    Mat4 operator+(const Mat4&) const;
    Mat4 operator-(const Mat4&) const;

    Mat4 operator*(float scalar) const;
    Mat4 operator/(float scalar) const;

    Mat4 operator*(const Mat4&) const;
    Vec4 operator*(const Vec4&) const;

    Mat4& operator+=(const Mat4&);
    Mat4& operator-=(const Mat4&);
    Mat4& operator*=(float);
    Mat4& operator/=(float);

    bool operator==(const Mat4&) const;
    bool operator!=(const Mat4&) const;

    // Matrix operations
    Mat4 Transpose() const;

    float Determinant() const;
    Mat4 Inverse() const;
};

}