#ifndef MAT2_H
#define MAT2_H

#include "Vec2.h"

namespace Math {
class Mat2 {
public:
    float m00, m01;
    float m10, m11;

    // Constructors
    Mat2();
    Mat2(float m00, float m01, float m10, float m11);

    // Static Utilities
    static Mat2 Identity();
    static Mat2 Zero();

    // Operator Overloads
    Mat2 operator+(const Mat2& other) const;
    Mat2 operator-(const Mat2& other) const;
    Mat2 operator*(float scalar) const;
    Mat2 operator/(float scalar) const;
    
    Mat2& operator+=(const Mat2& other);
    Mat2& operator-=(const Mat2& other);
    Mat2& operator*=(float scalar);
    Mat2& operator/=(float scalar);
    
    Mat2 operator*(const Mat2& other) const;
    Vec2 operator*(const Vec2& vector) const; 
    
    bool operator==(const Mat2& other) const;
    bool operator!=(const Mat2& other) const;

    // Matrix Operations
    float Determinant() const;
    float Trace() const;
    void Transpose();
    Mat2 Transposed() const;
    bool Invert();
    Mat2 Inverse() const;
    
    // Checks
    bool IsIdentity() const;
    bool IsZero() const;
};

// Enables float * Mat2 syntax
inline Mat2 operator*(float scalar, const Mat2& matrix) {
    return matrix * scalar;
}

} // namespace Math

#endif