#pragma once
#include "Vec3.h"
#include "Mat4.h"

namespace Math
{
    class Quaternion{
        public:
        float x ,y ,z, w;

        Quaternion();
        Quaternion(float x, float y, float z, float w);
        static Quaternion Identity();
        static Quaternion FromAxisAngle(const Vec3& axis, float angleRad);
        float Length() const;
        float LengthSquared() const;
        void Normalize();
        Quaternion Normalized() const;
        Quaternion Conjugate() const;
        Quaternion Inverse() const;
        float Dot(const Quaternion& other) const;
        Vec3 Rotate(const Vec3& vector) const;
        Mat4 ToMatrix() const;
        Quaternion operator+(const Quaternion& other) const;
        Quaternion operator-(const Quaternion& other) const;
        Quaternion operator*(const Quaternion& other) const;
        Quaternion operator*(float scalar) const;
        Quaternion operator/(float scalar) const;
        Quaternion& operator+=(const Quaternion& other);
        Quaternion& operator-=(const Quaternion& other);
        Quaternion& operator*=(const Quaternion& other);
        Quaternion& operator*=(float scalar);
        Quaternion& operator/=(float scalar);
        Quaternion operator-() const;
        bool operator==(const Quaternion& other) const;
        bool operator!=(const Quaternion& other) const;
    };
}