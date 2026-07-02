#include "Mat2.h"
#include "MathUtils.h"
#include <cmath>

namespace Math {
Mat2::Mat2() {
    m00 = 0.0f; m01 = 0.0f; m10 = 0.0f; m11 = 0.0f;
}

Mat2::Mat2(float m00, float m01, float m10, float m11) {
    this->m00 = m00;
    this->m01 = m01;
    this->m10 = m10;
    this->m11 = m11;
}

Mat2 Mat2::Identity() {
    return Mat2(
        1.0f, 0.0f,
        0.0f, 1.0f
    );
}

Mat2 Mat2::Zero() {
    return Mat2(
        0.0f, 0.0f,
        0.0f, 0.0f
    );
}

Mat2 Mat2::operator+(const Mat2& other) const {
    return Mat2(
        m00 + other.m00, m01 + other.m01,
        m10 + other.m10, m11 + other.m11
    );
}

Mat2 Mat2::operator-(const Mat2& other) const {
    return Mat2(
        m00 - other.m00, m01 - other.m01,
        m10 - other.m10, m11 - other.m11
    );
}

Mat2 Mat2::operator*(float scalar) const {
    return Mat2(
        m00 * scalar, m01 * scalar,
        m10 * scalar, m11 * scalar
    );
}

Mat2 Mat2::operator/(float scalar) const {
    float invScalar = 1.0f / scalar;
    return Mat2(
        m00 * invScalar, m01 * invScalar,
        m10 * invScalar, m11 * invScalar
    );
}

Mat2& Mat2::operator+=(const Mat2& other) {
    m00 += other.m00;
    m01 += other.m01;
    m10 += other.m10;
    m11 += other.m11;
    return *this;
}

Mat2& Mat2::operator-=(const Mat2& other) {
    m00 -= other.m00;
    m01 -= other.m01;
    m10 -= other.m10;
    m11 -= other.m11;
    return *this;
}

Mat2& Mat2::operator*=(float scalar) {
    m00 *= scalar;
    m01 *= scalar;
    m10 *= scalar;
    m11 *= scalar;
    return *this;
}

Mat2& Mat2::operator/=(float scalar) {
    float invScalar = 1.0f / scalar;
    m00 *= invScalar;
    m01 *= invScalar;
    m10 *= invScalar;
    m11 *= invScalar;
    return *this;
}

Mat2 Mat2::operator*(const Mat2& other) const {
    return Mat2(
        m00 * other.m00 + m01 * other.m10,
        m00 * other.m01 + m01 * other.m11,

        m10 * other.m00 + m11 * other.m10,
        m10 * other.m01 + m11 * other.m11
    );
}

Vec2 Mat2::operator*(const Vec2& vector) const {
    return Vec2(
        m00 * vector.x + m01 * vector.y,
        m10 * vector.x + m11 * vector.y
    );
}

float Mat2::Determinant() const {
    return (m00 * m11) - (m01 * m10);
}

float Mat2::Trace() const {
    return m00 + m11;
}

void Mat2::Transpose() {
    float temp = m01;
    m01 = m10;
    m10 = temp;
}

Mat2 Mat2::Transposed() const {
    return Mat2(
        m00, m10,
        m01, m11
    );
}

Mat2 Mat2::Inverse() const {
    float det = Determinant();
    if(Math::IsZero(det)) {
        return Mat2::Zero();
    }

    float invDet = 1.0f / det;
    return Mat2(
         m11 * invDet, -m01 * invDet,
        -m10 * invDet,  m00 * invDet
    );
}

bool Mat2::Invert() {
    float det = Determinant();
    if(Math::IsZero(det)) {
        return false;
    }

    float invDet = 1.0f / det;
    float tempM00 = m00;

    m00 =  m11 * invDet;
    m01 = -m01 * invDet;
    m10 = -m10 * invDet;
    m11 =  tempM00 * invDet;

    return true;
}

bool Mat2::IsIdentity() const {
    return *this == Identity();
}

bool Mat2::IsZero() const {
    return *this == Zero();
}

bool Mat2::operator==(const Mat2& other) const
{
    return Math::NearlyEqual(m00, other.m00) &&
           Math::NearlyEqual(m01, other.m01) &&
           Math::NearlyEqual(m10, other.m10) &&
           Math::NearlyEqual(m11, other.m11);
}

bool Mat2::operator!=(const Mat2& other) const {
    return !(*this == other);
}
};