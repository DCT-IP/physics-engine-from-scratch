#include "MathUtils.h"
#include <cmath>
namespace Math
{
    bool NearlyEqual(float a, float b)
    {
        return std::fabs(a-b) <= EPSILON;
    }
    float Clamp(float val, float min, float max)
    {
        if(val < min) return min;
        if(val > max) return max;
        return val;
    }
    float Lerp(float a, float b, float t)
    {
        return a + t*(b-a);
    }
    float Min(float a, float b)
    {
        return (a < b) ? a : b;
    }
    float Max(float a, float b)
    {
        return (a > b) ? a : b;
    }
    float Abs(float value)
    {
        return std::fabs(value);
    }
    float Sign(float value)
    {
        if (value > 0.0f)
            return 1.0f;
        if (value < 0.0f)
            return -1.0f;
        return 0.0f;
    }
    float DegreesToRadians(float degrees)
    {
        return degrees * (PI / 180.0f);
    }
    float RadiansToDegrees(float radians)
    {
        return radians * (180.0f / PI);
    }
    float Square(float value)
    {
        return value * value;
    }
    float Cube(float value)
    {
        return value * value * value;
    }
    bool IsZero(float value)
    {
        return Abs(value) < EPSILON;
    }
    bool IsFinite(float value)
    {
        return std::isfinite(value);
    }
}