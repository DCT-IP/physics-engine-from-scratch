#ifndef MAT2_H
#define MAT2_H

#include "Vec2.h"

class Mat2 {
public:
    float m00;
    float m01;
    float m10;
    float m11;

    // Constructors
    Mat2();
    Mat2(float m00, float m01, float m10, float m11);

    // Static Utilities
    static Mat2 Identity();
    static Mat2 Zero(); // Added: Was missing from header

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
    float Trace() const; // Added: Was missing from header
    void Transpose();
    Mat2 Transposed() const;
    bool Invert();
    Mat2 Inverse() const;
    
    // Checks
    bool IsIdentity() const;
    bool IsZero() const;
};

#endif