#include "Transform2D.h"
#include "MathUtils.h"

namespace Math
{

Transform2D::Transform2D()
    : position(0.0f, 0.0f),
      rotation(0.0f),
      scale(1.0f, 1.0f)
{
}

Transform2D::Transform2D(
    const Vec2& position,
    float rotation,
    const Vec2& scale
)
    : position(position),
      rotation(rotation),
      scale(scale)
{
}

Transform2D Transform2D::Identity()
{
    return Transform2D(
        Vec2(0.0f, 0.0f),
        0.0f,
        Vec2(1.0f, 1.0f)
    );
}

void Transform2D::Translate(const Vec2& delta)
{
    position += delta;
}

void Transform2D::Rotate(float angle)
{
    rotation += angle;
}

void Transform2D::Scale(const Vec2& factor)
{
    scale.x *= factor.x;
    scale.y *= factor.y;
}

bool Transform2D::operator==(const Transform2D& other) const
{
    return position == other.position &&
           Math::NearlyEqual(rotation, other.rotation) &&
           scale == other.scale;
}

bool Transform2D::operator!=(const Transform2D& other) const
{
    return !(*this == other);
}

}