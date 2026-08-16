#pragma once
#include "Vec3.h"
#include "Mat4.h"

namespace Math
{
class Transform3D
{
public:
    Transform3D();
    Transform3D(
        const Vec3& position,
        const Vec3& scale
    );
    Vec3 GetPosition() const;
    void SetPosition(const Vec3& position);
    Vec3 GetScale() const;
    void SetScale(const Vec3& scale);
    void Translate(const Vec3& translation);
    void Scale(const Vec3& scale);
    Mat4 ToMatrix() const;
    Vec3 TransformPoint(const Vec3& point) const;
private:
    Vec3 position;
    Vec3 scale;
};

}