#pragma once
#include "Vec3.h"
namespace Math
{
class Mat3
{
public:
    // =========================
    // Data
    // =========================
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
    // =========================
    // Constructors
    // =========================
    Mat3();
    Mat3(
        float m00, float m01, float m02,
        float m10, float m11, float m12,
        float m20, float m21, float m22
    );
    // =========================
    // Static Utilities
    // =========================
    static Mat3 Identity();
    static Mat3 Zero();
    // =========================
    // Arithmetic
    // =========================
    Mat3 operator+(const Mat3&) const;
    Mat3 operator-(const Mat3&) const;
    Mat3 operator*(float scalar) const;
    Mat3 operator/(float scalar) const;
    Mat3& operator+=(const Mat3&);
    Mat3& operator-=(const Mat3&);
    Mat3& operator*=(float scalar);
    Mat3& operator/=(float scalar);
    Mat3 operator*(const Mat3&) const;
    Vec3 operator*(const Vec3&) const;
    bool operator==(const Mat3&) const;
    bool operator!=(const Mat3&) const;
    // =========================
    // Matrix Operations
    // =========================
    float Determinant() const;
    float Trace() const;
    void Transpose();
    Mat3 Transposed() const;
    bool Invert();
    Mat3 Inverse() const;
    // =========================
    // Checks
    // =========================
    bool IsIdentity() const;
    bool IsZero() const;
    // =========================
    // 2D Transformations
    // =========================
    static Mat3 Rotation(float radians);
    static Mat3 Scale(float sx, float sy);
    static Mat3 Translation(float tx, float ty);
};
}