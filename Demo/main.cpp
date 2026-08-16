#include <iostream>
#include <cassert>
#include "../Core/Math/Vec2.h"
#include "../Core/Math/Mat2.h"
#include "../Core/Math/MathUtils.h"
#include "../Core/Math/Vec3.h"
#include "../Core/Math/Mat3.h"
#include "../Core/Math/Vec4.h"
#include "../Core/Math/Mat4.h"
#include "../Core/Math/Transform2D.h"
#include "../Core/Math/Transform3D.h"

using namespace Math;

int main()
{
    // ==========================================
    // Mat2 Demo
    // ==========================================
    std::cout << "\n======================== Mat2 Demo =============================\n";

    Mat2 mat2A(1.0f, 2.0f,
               3.0f, 4.0f);

    Mat2 mat2B(5.0f, 6.0f,
               7.0f, 8.0f);

    std::cout << "Matrix A\n";
    std::cout << mat2A.m00 << " " << mat2A.m01 << "\n";
    std::cout << mat2A.m10 << " " << mat2A.m11 << "\n\n";

    std::cout << "Matrix B\n";
    std::cout << mat2B.m00 << " " << mat2B.m01 << "\n";
    std::cout << mat2B.m10 << " " << mat2B.m11 << "\n\n";

    Mat2 mat2C = mat2A + mat2B;
    std::cout << "A + B\n";
    std::cout << mat2C.m00 << " " << mat2C.m01 << "\n";
    std::cout << mat2C.m10 << " " << mat2C.m11 << "\n\n";

    mat2C = mat2A - mat2B;
    std::cout << "A - B\n";
    std::cout << mat2C.m00 << " " << mat2C.m01 << "\n";
    std::cout << mat2C.m10 << " " << mat2C.m11 << "\n\n";

    mat2C = mat2A * 2.0f;
    std::cout << "A * 2\n";
    std::cout << mat2C.m00 << " " << mat2C.m01 << "\n";
    std::cout << mat2C.m10 << " " << mat2C.m11 << "\n\n";

    mat2C = mat2A * mat2B;
    std::cout << "A * B\n";
    std::cout << mat2C.m00 << " " << mat2C.m01 << "\n";
    std::cout << mat2C.m10 << " " << mat2C.m11 << "\n\n";

    Vec2 v2(2.0f, 3.0f);
    Vec2 vec2Result = mat2A * v2;
    std::cout << "A * Vec2 = (" << vec2Result.x << ", " << vec2Result.y << ")\n\n";

    std::cout << "Determinant = " << mat2A.Determinant() << "\n\n";
    std::cout << "Trace = " << mat2A.Trace() << "\n\n";

    mat2C = mat2A.Transposed();
    std::cout << "Transpose\n";
    std::cout << mat2C.m00 << " " << mat2C.m01 << "\n";
    std::cout << mat2C.m10 << " " << mat2C.m11 << "\n\n";

    mat2C = mat2A.Inverse();
    std::cout << "Inverse\n";
    std::cout << mat2C.m00 << " " << mat2C.m01 << "\n";
    std::cout << mat2C.m10 << " " << mat2C.m11 << "\n";

    // ==========================================
    // MathUtils Demo
    // ==========================================
    std::cout << "\n========== MathUtils Demo ==========\n\n";

    std::cout << "PI = " << Math::PI << '\n';
    std::cout << "TWO_PI = " << Math::TWO_PI << '\n';
    std::cout << "HALF_PI = " << Math::HALF_PI << "\n\n";

    std::cout << "Clamp(15, 0, 10) = " << Math::Clamp(15.0f, 0.0f, 10.0f) << '\n';
    std::cout << "Lerp(0, 100, 0.25) = " << Math::Lerp(0.0f, 100.0f, 0.25f) << '\n';
    std::cout << "Min(3, 7) = " << Math::Min(3.0f, 7.0f) << '\n';
    std::cout << "Max(3, 7) = " << Math::Max(3.0f, 7.0f) << '\n';
    std::cout << "Abs(-42) = " << Math::Abs(-42.0f) << '\n';
    std::cout << "Sign(-10) = " << Math::Sign(-10.0f) << '\n';
    std::cout << "90 Degrees = " << Math::DegreesToRadians(90.0f) << " radians\n";
    std::cout << "PI Radians = " << Math::RadiansToDegrees(Math::PI) << " degrees\n";
    std::cout << "Square(6) = " << Math::Square(6.0f) << '\n';
    std::cout << "Cube(4) = " << Math::Cube(4.0f) << '\n';
    std::cout << "NearlyEqual(1.0, 1.0000001) = " << Math::NearlyEqual(1.0f, 1.0000001f) << '\n';
    std::cout << "IsZero(0.00000001) = " << Math::IsZero(0.00000001f) << '\n';
    std::cout << "IsFinite(42) = " << Math::IsFinite(42.0f) << '\n';

    // ==========================================
    // Vec3 Demo
    // ==========================================
    std::cout << "\n========== Vec3 Demo ==========\n\n";

    Vec3 vec3A(1.0f, 2.0f, 3.0f);
    Vec3 vec3B(4.0f, 5.0f, 6.0f);

    std::cout << "A = (" << vec3A.x << ", " << vec3A.y << ", " << vec3A.z << ")\n";
    std::cout << "B = (" << vec3B.x << ", " << vec3B.y << ", " << vec3B.z << ")\n\n";

    Vec3 vec3Add = vec3A + vec3B;
    std::cout << "A + B = (" << vec3Add.x << ", " << vec3Add.y << ", " << vec3Add.z << ")\n";

    Vec3 vec3Sub = vec3A - vec3B;
    std::cout << "A - B = (" << vec3Sub.x << ", " << vec3Sub.y << ", " << vec3Sub.z << ")\n";

    Vec3 vec3Mul = vec3A * 2.0f;
    std::cout << "A * 2 = (" << vec3Mul.x << ", " << vec3Mul.y << ", " << vec3Mul.z << ")\n";

    Vec3 vec3Div = vec3A / 2.0f;
    std::cout << "A / 2 = (" << vec3Div.x << ", " << vec3Div.y << ", " << vec3Div.z << ")\n";

    std::cout << "Length(A) = " << vec3A.Length() << '\n';
    std::cout << "Dot(A, B) = " << vec3A.Dot(vec3B) << '\n';

    Vec3 vec3Cross = vec3A.Cross(vec3B);
    std::cout << "Cross(A, B) = (" << vec3Cross.x << ", " << vec3Cross.y << ", " << vec3Cross.z << ")\n";

    std::cout << "Distance(A, B) = " << vec3A.Distance(vec3B) << '\n';

    Vec3 vec3Norm = vec3A.Normalized();
    std::cout << "Normalized A = (" << vec3Norm.x << ", " << vec3Norm.y << ", " << vec3Norm.z << ")\n";

    Vec3 vec3Zero;
    std::cout << "Zero Vector? " << (vec3Zero.IsZero() ? "Yes" : "No") << '\n';

    // ==========================================
    // Mat3 Demo
    // ==========================================
    std::cout << "\n========== Mat3 Demo ==========\n\n";

    Mat3 mat3A(1, 2, 3,
               4, 5, 6,
               7, 8, 10);

    Mat3 mat3B(9, 8, 7,
               6, 5, 4,
               3, 2, 1);

    std::cout << "Matrix A:\n";
    std::cout << mat3A.m00 << " " << mat3A.m01 << " " << mat3A.m02 << "\n";
    std::cout << mat3A.m10 << " " << mat3A.m11 << " " << mat3A.m12 << "\n";
    std::cout << mat3A.m20 << " " << mat3A.m21 << " " << mat3A.m22 << "\n\n";

    std::cout << "Matrix B:\n";
    std::cout << mat3B.m00 << " " << mat3B.m01 << " " << mat3B.m02 << "\n";
    std::cout << mat3B.m10 << " " << mat3B.m11 << " " << mat3B.m12 << "\n";
    std::cout << mat3B.m20 << " " << mat3B.m21 << " " << mat3B.m22 << "\n\n";

    Mat3 mat3D = mat3A + mat3B;
    std::cout << "A + B:\n";
    std::cout << mat3D.m00 << " " << mat3D.m01 << " " << mat3D.m02 << "\n";
    std::cout << mat3D.m10 << " " << mat3D.m11 << " " << mat3D.m12 << "\n";
    std::cout << mat3D.m20 << " " << mat3D.m21 << " " << mat3D.m22 << "\n\n";

    Mat3 mat3E = mat3A - mat3B;
    std::cout << "A - B:\n";
    std::cout << mat3E.m00 << " " << mat3E.m01 << " " << mat3E.m02 << "\n";
    std::cout << mat3E.m10 << " " << mat3E.m11 << " " << mat3E.m12 << "\n";
    std::cout << mat3E.m20 << " " << mat3E.m21 << " " << mat3E.m22 << "\n\n";

    Mat3 mat3F = mat3A * 2.0f;
    std::cout << "A * 2.0:\n";
    std::cout << mat3F.m00 << " " << mat3F.m01 << " " << mat3F.m02 << "\n";
    std::cout << mat3F.m10 << " " << mat3F.m11 << " " << mat3F.m12 << "\n";
    std::cout << mat3F.m20 << " " << mat3F.m21 << " " << mat3F.m22 << "\n\n";

    Mat3 mat3G = mat3A * mat3B;
    std::cout << "A * B:\n";
    std::cout << mat3G.m00 << " " << mat3G.m01 << " " << mat3G.m02 << "\n";
    std::cout << mat3G.m10 << " " << mat3G.m11 << " " << mat3G.m12 << "\n";
    std::cout << mat3G.m20 << " " << mat3G.m21 << " " << mat3G.m22 << "\n\n";

    Vec3 v3(1.0f, 2.0f, 3.0f);
    Vec3 vec3Result = mat3A * v3;
    std::cout << "A * Vec3 = (" << vec3Result.x << ", " << vec3Result.y << ", " << vec3Result.z << ")\n\n";

    std::cout << "Determinant(A) = " << mat3A.Determinant() << "\n";
    std::cout << "Trace(A) = " << mat3A.Trace() << "\n\n";

    Mat3 mat3H = mat3A.Transposed();
    std::cout << "Transpose(A):\n";
    std::cout << mat3H.m00 << " " << mat3H.m01 << " " << mat3H.m02 << "\n";
    std::cout << mat3H.m10 << " " << mat3H.m11 << " " << mat3H.m12 << "\n";
    std::cout << mat3H.m20 << " " << mat3H.m21 << " " << mat3H.m22 << "\n\n";

    Mat3 mat3I = mat3A.Inverse();
    std::cout << "Inverse(A):\n";
    std::cout << mat3I.m00 << " " << mat3I.m01 << " " << mat3I.m02 << "\n";
    std::cout << mat3I.m10 << " " << mat3I.m11 << " " << mat3I.m12 << "\n";
    std::cout << mat3I.m20 << " " << mat3I.m21 << " " << mat3I.m22 << "\n\n";

    std::cout << "Is Identity? " << (mat3A.IsIdentity() ? "Yes" : "No") << "\n";
    std::cout << "Is Zero? " << (mat3A.IsZero() ? "Yes" : "No") << "\n\n";

    Mat3 rot = Mat3::Rotation(Math::HALF_PI);
    Mat3 scale = Mat3::Scale(2.0f, 3.0f);
    Mat3 trans = Mat3::Translation(5.0f, -2.0f);

    Vec3 point2D(1.0f, 0.0f, 1.0f);
    Vec3 translatedPoint = trans * point2D;

    std::cout << "Translation (5, -2) of (1, 0, 1) = (" 
              << translatedPoint.x << ", " 
              << translatedPoint.y << ", " 
              << translatedPoint.z << ")\n";
    Vec4 a;
    assert(a.IsZero());

    Vec4 b(1,2,3,4);
    Vec4 c(5,6,7,8);

    assert((b+c)==Vec4(6,8,10,12));
    assert((c-b)==Vec4(4,4,4,4));
    assert((b*2)==Vec4(2,4,6,8));
    assert((b/2)==Vec4(0.5f,1,1.5f,2));

    Vec4 d=b;
    d+=c;
    assert(d==Vec4(6,8,10,12));

    d=b;
    d-=c;
    assert(d==Vec4(-4,-4,-4,-4));

    d=b;
    d*=2;
    assert(d==Vec4(2,4,6,8));

    d/=2;
    assert(d==b);

    assert((-b)==Vec4(-1,-2,-3,-4));

    assert(b.Dot(c)==70.0f);

    assert(b.LengthSquared()==30.0f);

    Vec4 n=b.Normalized();
    assert(std::abs(n.Length()-1.0f)<1e-5f);

    std::cout<<"All Vec4 tests passed!\n";
    std::cout << "\n========== Mat4 ==========\n";

    Math::Mat4 A(
        1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,14,15,16
    );

    Math::Mat4 I = Math::Mat4::Identity();

    Math::Mat4 add = A + I;
    Math::Mat4 sub = A - I;
    Math::Mat4 mul = A * 2.0f;
    Math::Mat4 mat4Trans = A.Transpose(); // Changed from 'trans' to avoid redefinition error

    Math::Vec4 v(1,2,3,1);
    Math::Vec4 result = I * v;

    std::cout << "Identity * Vec4 = ("
              << result.x << ", "
              << result.y << ", "
              << result.z << ", "
              << result.w << ")\n";

    std::cout << "Transpose completed.\n";
    std::cout << "Matrix multiplication completed.\n";
    std::cout << "=========================================================\n";
    std::cout << "\n===== Transform2D =====\n";

Math::Transform2D transform;

std::cout << "Initial Transform:\n";
std::cout << "Position = ("
          << transform.position.x << ", "
          << transform.position.y << ")\n";

std::cout << "Rotation = "
          << transform.rotation << "\n";

std::cout << "Scale = ("
          << transform.scale.x << ", "
          << transform.scale.y << ")\n\n";

// Translation
transform.Translate(Math::Vec2(5.0f, 3.0f));

std::cout << "After Translation:\n";
std::cout << "Position = ("
          << transform.position.x << ", "
          << transform.position.y << ")\n\n";

// Rotation
transform.Rotate(1.5708f);

std::cout << "After Rotation:\n";
std::cout << "Rotation = "
          << transform.rotation << " radians\n\n";

// Scale
transform.Scale(Math::Vec2(2.0f, 3.0f));

std::cout << "After Scaling:\n";
std::cout << "Scale = ("
          << transform.scale.x << ", "
          << transform.scale.y << ")\n\n";

// Identity
Math::Transform2D identity = Math::Transform2D::Identity();

std::cout << "Identity Transform:\n";
std::cout << "Position = ("
          << identity.position.x << ", "
          << identity.position.y << ")\n";

std::cout << "Rotation = "
          << identity.rotation << "\n";

std::cout << "Scale = ("
          << identity.scale.x << ", "
          << identity.scale.y << ")\n\n";
    std::cout << "=========================================================\n";

    std::cout << "\n===== Transform3D =====\n";

Math::Transform3D transform3(
    Math::Vec3(10.0f, 20.0f, 30.0f),
    Math::Vec3(2.0f, 2.0f, 2.0f)
);

Math::Vec3 point(1.0f, 2.0f, 3.0f);

Math::Vec3 transformed = transform3.TransformPoint(point);

std::cout << "Original Point: ("
          << point.x << ", "
          << point.y << ", "
          << point.z << ")\n";

std::cout << "Position: ("
          << transform3.GetPosition().x << ", "
          << transform3.GetPosition().y << ", "
          << transform3.GetPosition().z << ")\n";

std::cout << "Scale: ("
          << transform3.GetScale().x << ", "
          << transform3.GetScale().y << ", "
          << transform3.GetScale().z << ")\n";

std::cout << "Transformed Point: ("
          << transformed.x << ", "
          << transformed.y << ", "
          << transformed.z << ")\n";

transform3.Translate(Math::Vec3(1.0f, 2.0f, 3.0f));

std::cout << "After Translation: ("
          << transform3.GetPosition().x << ", "
          << transform3.GetPosition().y << ", "
          << transform3.GetPosition().z << ")\n";

transform3.Scale(Math::Vec3(2.0f, 2.0f, 2.0f));

std::cout << "After Scaling: ("
          << transform3.GetScale().x << ", "
          << transform3.GetScale().y << ", "
          << transform3.GetScale().z << ")\n";
              std::cout << "=========================================================\n";


    return 0;
}