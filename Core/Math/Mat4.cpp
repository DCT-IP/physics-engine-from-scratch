#include "Mat4.h"
#include "MathUtils.h"

namespace Math
{

Mat4::Mat4()
{
    m00 = m01 = m02 = m03 = 0.0f;
    m10 = m11 = m12 = m13 = 0.0f;
    m20 = m21 = m22 = m23 = 0.0f;
    m30 = m31 = m32 = m33 = 0.0f;
}

Mat4::Mat4(
    float m00,float m01,float m02,float m03,
    float m10,float m11,float m12,float m13,
    float m20,float m21,float m22,float m23,
    float m30,float m31,float m32,float m33)
{
    this->m00=m00; this->m01=m01; this->m02=m02; this->m03=m03;
    this->m10=m10; this->m11=m11; this->m12=m12; this->m13=m13;
    this->m20=m20; this->m21=m21; this->m22=m22; this->m23=m23;
    this->m30=m30; this->m31=m31; this->m32=m32; this->m33=m33;
}

Mat4 Mat4::Identity()
{
    return Mat4(
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    );
}

Mat4 Mat4::operator+(const Mat4& other) const
{
    return Mat4(
        m00+other.m00,m01+other.m01,m02+other.m02,m03+other.m03,
        m10+other.m10,m11+other.m11,m12+other.m12,m13+other.m13,
        m20+other.m20,m21+other.m21,m22+other.m22,m23+other.m23,
        m30+other.m30,m31+other.m31,m32+other.m32,m33+other.m33
    );
}

Mat4 Mat4::operator-(const Mat4& other) const
{
    return Mat4(
        m00-other.m00,m01-other.m01,m02-other.m02,m03-other.m03,
        m10-other.m10,m11-other.m11,m12-other.m12,m13-other.m13,
        m20-other.m20,m21-other.m21,m22-other.m22,m23-other.m23,
        m30-other.m30,m31-other.m31,m32-other.m32,m33-other.m33
    );
}

Mat4 Mat4::operator*(float scalar) const
{
    return Mat4(
        m00*scalar,m01*scalar,m02*scalar,m03*scalar,
        m10*scalar,m11*scalar,m12*scalar,m13*scalar,
        m20*scalar,m21*scalar,m22*scalar,m23*scalar,
        m30*scalar,m31*scalar,m32*scalar,m33*scalar
    );
}

Mat4 Mat4::operator/(float scalar) const
{
    float inv = 1.0f / scalar;
    return (*this) * inv;
}

Mat4& Mat4::operator+=(const Mat4& other)
{
    *this = *this + other;
    return *this;
}

Mat4& Mat4::operator-=(const Mat4& other)
{
    *this = *this - other;
    return *this;
}

Mat4& Mat4::operator*=(float scalar)
{
    *this = *this * scalar;
    return *this;
}

Mat4& Mat4::operator/=(float scalar)
{
    *this = *this / scalar;
    return *this;
}

bool Mat4::operator==(const Mat4& other) const
{
    return
        NearlyEqual(m00,other.m00)&&
        NearlyEqual(m01,other.m01)&&
        NearlyEqual(m02,other.m02)&&
        NearlyEqual(m03,other.m03)&&

        NearlyEqual(m10,other.m10)&&
        NearlyEqual(m11,other.m11)&&
        NearlyEqual(m12,other.m12)&&
        NearlyEqual(m13,other.m13)&&

        NearlyEqual(m20,other.m20)&&
        NearlyEqual(m21,other.m21)&&
        NearlyEqual(m22,other.m22)&&
        NearlyEqual(m23,other.m23)&&

        NearlyEqual(m30,other.m30)&&
        NearlyEqual(m31,other.m31)&&
        NearlyEqual(m32,other.m32)&&
        NearlyEqual(m33,other.m33);
}

bool Mat4::operator!=(const Mat4& other) const
{
    return !(*this==other);
}

Mat4 Mat4::Transpose() const
{
    return Mat4(
        m00,m10,m20,m30,
        m01,m11,m21,m31,
        m02,m12,m22,m32,
        m03,m13,m23,m33
    );
}

Vec4 Mat4::operator*(const Vec4& v) const
{
    return Vec4(
        m00*v.x + m01*v.y + m02*v.z + m03*v.w,
        m10*v.x + m11*v.y + m12*v.z + m13*v.w,
        m20*v.x + m21*v.y + m22*v.z + m23*v.w,
        m30*v.x + m31*v.y + m32*v.z + m33*v.w
    );
}

Mat4 Mat4::operator*(const Mat4& o) const
{
    return Mat4(

        m00*o.m00+m01*o.m10+m02*o.m20+m03*o.m30,
        m00*o.m01+m01*o.m11+m02*o.m21+m03*o.m31,
        m00*o.m02+m01*o.m12+m02*o.m22+m03*o.m32,
        m00*o.m03+m01*o.m13+m02*o.m23+m03*o.m33,

        m10*o.m00+m11*o.m10+m12*o.m20+m13*o.m30,
        m10*o.m01+m11*o.m11+m12*o.m21+m13*o.m31,
        m10*o.m02+m11*o.m12+m12*o.m22+m13*o.m32,
        m10*o.m03+m11*o.m13+m12*o.m23+m13*o.m33,

        m20*o.m00+m21*o.m10+m22*o.m20+m23*o.m30,
        m20*o.m01+m21*o.m11+m22*o.m21+m23*o.m31,
        m20*o.m02+m21*o.m12+m22*o.m22+m23*o.m32,
        m20*o.m03+m21*o.m13+m22*o.m23+m23*o.m33,

        m30*o.m00+m31*o.m10+m32*o.m20+m33*o.m30,
        m30*o.m01+m31*o.m11+m32*o.m21+m33*o.m31,
        m30*o.m02+m31*o.m12+m32*o.m22+m33*o.m32,
        m30*o.m03+m31*o.m13+m32*o.m23+m33*o.m33
    );
}

// TODO 
// float Mat4::Determinant() const
// {
// }

// TODO 
// Mat4 Mat4::Inverse() const
// {
// }

}