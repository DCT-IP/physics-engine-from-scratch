#ifndef MATHUTILS_H
#define MATHUTILS_H

namespace Math
{
    // ==========================================================
    // Constants
    // ==========================================================

    constexpr float PI       = 3.14159265358979323846f;
    constexpr float TWO_PI   = 2.0f * PI;
    constexpr float HALF_PI  = PI * 0.5f;
    constexpr float EPSILON  = 1e-6f;

    // ==========================================================
    // Utility Functions
    // ==========================================================

    bool NearlyEqual(float a, float b);
    float Clamp(float value, float min, float max);
    float Lerp(float a, float b, float t);
    float Min(float a, float b);
    float Max(float a, float b);
    float Abs(float value);
    float Sign(float value);
    float DegreesToRadians(float degrees);
    float RadiansToDegrees(float radians);
    float Square(float value);
    float Cube(float value);
    bool IsZero(float value);
    bool IsFinite(float value);
}

#endif