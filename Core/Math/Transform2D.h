#pragma once 

#include "Vec2.h"
#include "MathUtils.h"
namespace Math
{
    class Transform2D
    {
        public:
        Vec2 position;
        float rotation;
        Vec2 scale;
        Transform2D();
        Transform2D(const Vec2& position, float rotation, const Vec2& scale);
        static Transform2D Identity();
        void Translate(const Vec2& delta);
        void Rotate(float angle);
        void Scale(const Vec2& factor);
        bool operator==(const Transform2D& other)const;
        bool operator!=(const Transform2D& other)const;
    };
}