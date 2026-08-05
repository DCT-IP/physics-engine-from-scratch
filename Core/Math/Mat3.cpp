#include "Mat3.h"
#include "MathUtils.h"
#include <cmath>
#include <utility>

namespace Math {

// =========================
// Constructors
// =========================

Mat3::Mat3() {
    m00 = 0.0f; m01 = 0.0f; m02 = 0.0f;
    m10 = 0.0f; m11 = 0.0f; m12 = 0.0f;
    m20 = 0.0f; m21 = 0.0f; m22 = 0.0f;
}

Mat3::Mat3(
    float m00, float m01, float m02,
    float m10, float m11, float m12,
    float m20, float m21, float m22
) {
    this->m00 = m00; this->m01 = m01; this->m02 = m02;
    this->m10 = m10; this->m11 = m11; this->m12 = m12;
    this->m20 = m20; this->m21 = m21; this->m22 = m22;
}

// =========================
// Static Utilities
// =========================

Mat3 Mat3::Identity() {
    return Mat3(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    );
}

Mat3 Mat3::Zero() {
    return Mat3(
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f
    );
}

// =========================
// Arithmetic Operators
// =========================

Mat3 Mat3::operator+(const Mat3& other) const {
    return Mat3(
        m00 + other.m00, m01 + other.m01, m02 + other.m02,
        m10 + other.m10, m11 + other.m11, m12 + other.m12,
        m20 + other.m20, m21 + other.m21, m22 + other.m22
    );
}

Mat3 Mat3::operator-(const Mat3& other) const {
    return Mat3(
        m00 - other.m00, m01 - other.m01, m02 - other.m02,
        m10 - other.m10, m11 - other.m11, m12 - other.m12,
        m20 - other.m20, m21 - other.m21, m22 - other.m22
    );
}

Mat3 Mat3::operator*(float scalar) const {
    return Mat3(
        m00 * scalar, m01 * scalar, m02 * scalar,
        m10 * scalar, m11 * scalar, m12 * scalar,
        m20 * scalar, m21 * scalar, m22 * scalar
    );
}

Mat3 Mat3::operator/(float scalar) const {
    float invScalar = 1.0f / scalar;
    return Mat3(
        m00 * invScalar, m01 * invScalar, m02 * invScalar,
        m10 * invScalar, m11 * invScalar, m12 * invScalar,
        m20 * invScalar, m21 * invScalar, m22 * invScalar
    );
}

Mat3& Mat3::operator+=(const Mat3& other) {
    m00 += other.m00; m01 += other.m01; m02 += other.m02;
    m10 += other.m10; m11 += other.m11; m12 += other.m12;
    m20 += other.m20; m21 += other.m21; m22 += other.m22;
    return *this;
}

Mat3& Mat3::operator-=(const Mat3& other) {
    m00 -= other.m00; m01 -= other.m01; m02 -= other.m02;
    m10 -= other.m10; m11 -= other.m11; m12 -= other.m12;
    m20 -= other.m20; m21 -= other.m21; m22 -= other.m22;
    return *this;
}

Mat3& Mat3::operator*=(float scalar) {
    m00 *= scalar; m01 *= scalar; m02 *= scalar;
    m10 *= scalar; m11 *= scalar; m12 *= scalar;
    m20 *= scalar; m21 *= scalar; m22 *= scalar;
    return *this;
}

Mat3& Mat3::operator/=(float scalar) {
    float invScalar = 1.0f / scalar;
    m00 *= invScalar; m01 *= invScalar; m02 *= invScalar;
    m10 *= invScalar; m11 *= invScalar; m12 *= invScalar;
    m20 *= invScalar; m21 *= invScalar; m22 *= invScalar;
    return *this;
}

Mat3 Mat3::operator*(const Mat3& other) const {
    return Mat3(
        m00 * other.m00 + m01 * other.m10 + m02 * other.m20,
        m00 * other.m01 + m01 * other.m11 + m02 * other.m21,
        m00 * other.m02 + m01 * other.m12 + m02 * other.m22,

        m10 * other.m00 + m11 * other.m10 + m12 * other.m20,
        m10 * other.m01 + m11 * other.m11 + m12 * other.m21,
        m10 * other.m02 + m11 * other.m12 + m12 * other.m22,

        m20 * other.m00 + m21 * other.m10 + m22 * other.m20,
        m20 * other.m01 + m21 * other.m11 + m22 * other.m21,
        m20 * other.m02 + m21 * other.m12 + m22 * other.m22
    );
}

Vec3 Mat3::operator*(const Vec3& vector) const {
    return Vec3(
        m00 * vector.x + m01 * vector.y + m02 * vector.z,
        m10 * vector.x + m11 * vector.y + m12 * vector.z,
        m20 * vector.x + m21 * vector.y + m22 * vector.z
    );
}

bool Mat3::operator==(const Mat3& other) const {
    return Math::NearlyEqual(m00, other.m00) &&
           Math::NearlyEqual(m01, other.m01) &&
           Math::NearlyEqual(m02, other.m02) &&
           Math::NearlyEqual(m10, other.m10) &&
           Math::NearlyEqual(m11, other.m11) &&
           Math::NearlyEqual(m12, other.m12) &&
           Math::NearlyEqual(m20, other.m20) &&
           Math::NearlyEqual(m21, other.m21) &&
           Math::NearlyEqual(m22, other.m22);
}

bool Mat3::operator!=(const Mat3& other) const {
    return !(*this == other);
}

// =========================
// Matrix Operations
// =========================

float Mat3::Determinant() const {
    return m00 * (m11 * m22 - m12 * m21) -
           m01 * (m10 * m22 - m12 * m20) +
           m02 * (m10 * m21 - m11 * m20);
}

float Mat3::Trace() const {
    return m00 + m11 + m22;
}

void Mat3::Transpose() {
    std::swap(m01, m10);
    std::swap(m02, m20);
    std::swap(m12, m21);
}

Mat3 Mat3::Transposed() const {
    return Mat3(
        m00, m10, m20,
        m01, m11, m21,
        m02, m12, m22
    );
}

Mat3 Mat3::Inverse() const {
    float det = Determinant();
    if (Math::IsZero(det)) {
        return Mat3::Zero();
    }

    float invDet = 1.0f / det;

    return Mat3(
        (m11 * m22 - m12 * m21) * invDet,
        (m02 * m21 - m01 * m22) * invDet,
        (m01 * m12 - m02 * m11) * invDet,

        (m12 * m20 - m10 * m22) * invDet,
        (m00 * m22 - m02 * m20) * invDet,
        (m02 * m10 - m00 * m12) * invDet,

        (m10 * m21 - m11 * m20) * invDet,
        (m01 * m20 - m00 * m21) * invDet,
        (m00 * m11 - m01 * m10) * invDet
    );
}

bool Mat3::Invert() {
    float det = Determinant();
    if (Math::IsZero(det)) {
        return false;
    }

    *this = Inverse();
    return true;
}

// =========================
// Checks
// =========================

bool Mat3::IsIdentity() const {
    return *this == Identity();
}

bool Mat3::IsZero() const {
    return *this == Zero();
}

// =========================
// 2D Transformations (Affine)
// =========================

Mat3 Mat3::Rotation(float radians) {
    float cosAngle = std::cos(radians);
    float sinAngle = std::sin(radians);

    return Mat3(
         cosAngle, -sinAngle, 0.0f,
         sinAngle,  cosAngle, 0.0f,
         0.0f,      0.0f,     1.0f
    );
}

Mat3 Mat3::Scale(float sx, float sy) {
    return Mat3(
          sx, 0.0f, 0.0f,
        0.0f,   sy, 0.0f,
        0.0f, 0.0f, 1.0f
    );
}

Mat3 Mat3::Translation(float tx, float ty) {
    return Mat3(
        1.0f, 0.0f,   tx,
        0.0f, 1.0f,   ty,
        0.0f, 0.0f, 1.0f
    );
}

} 