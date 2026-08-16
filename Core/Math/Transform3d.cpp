#include "Transform3D.h"

namespace Math
{

Transform3D::Transform3D()
    : position(0.0f, 0.0f, 0.0f),
      scale(1.0f, 1.0f, 1.0f)
{
}

Transform3D::Transform3D(
    const Vec3& position,
    const Vec3& scale
)
    : position(position),
      scale(scale)
{
}

Vec3 Transform3D::GetPosition() const
{
    return position;
}

void Transform3D::SetPosition(const Vec3& position)
{
    this->position = position;
}

Vec3 Transform3D::GetScale() const
{
    return scale;
}

void Transform3D::SetScale(const Vec3& scale)
{
    this->scale = scale;
}

void Transform3D::Translate(const Vec3& translation)
{
    position += translation;
}

void Transform3D::Scale(const Vec3& scale)
{
    this->scale.x *= scale.x;
    this->scale.y *= scale.y;
    this->scale.z *= scale.z;
}

Mat4 Transform3D::ToMatrix() const
{
    return Mat4(
        scale.x, 0.0f,   0.0f,   position.x,
        0.0f,   scale.y, 0.0f,   position.y,
        0.0f,   0.0f,   scale.z, position.z,
        0.0f,   0.0f,   0.0f,   1.0f
    );
}

Vec3 Transform3D::TransformPoint(const Vec3& point) const
{
    return Vec3(
        point.x * scale.x + position.x,
        point.y * scale.y + position.y,
        point.z * scale.z + position.z
    );
}

}