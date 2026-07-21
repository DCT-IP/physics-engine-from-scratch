#include <iostream>

#include "../Core/Math/Vec2.h"
#include "../Core/Math/Mat2.h"
#include "../Core/Math/MathUtils.h"
#include "../Core/Math/Vec3.h"


using namespace Math;
int main()
{
    Mat2 A(1,2,
           3,4);

    Mat2 B(5,6,
           7,8);
    std::cout << "\n========================demo=============================\n";
    std::cout << "Matrix A\n";
    std::cout << A.m00 << " " << A.m01 << "\n";
    std::cout << A.m10 << " " << A.m11 << "\n\n";

    std::cout << "Matrix B\n";
    std::cout << B.m00 << " " << B.m01 << "\n";
    std::cout << B.m10 << " " << B.m11 << "\n\n";

    Mat2 C = A + B;

    std::cout << "A + B\n";
    std::cout << C.m00 << " " << C.m01 << "\n";
    std::cout << C.m10 << " " << C.m11 << "\n\n";

    C = A - B;

    std::cout << "A - B\n";
    std::cout << C.m00 << " " << C.m01 << "\n";
    std::cout << C.m10 << " " << C.m11 << "\n\n";

    C = A * 2.0f;

    std::cout << "A * 2\n";
    std::cout << C.m00 << " " << C.m01 << "\n";
    std::cout << C.m10 << " " << C.m11 << "\n\n";

    C = A * B;

    std::cout << "A * B\n";
    std::cout << C.m00 << " " << C.m01 << "\n";
    std::cout << C.m10 << " " << C.m11 << "\n\n";

    Vec2 v(2,3);

    Vec2 r = A * v;

    std::cout << "A * Vec2 = ("
              << r.x << ", "
              << r.y << ")\n\n";

    std::cout << "Determinant = "
              << A.Determinant()
              << "\n\n";

    std::cout << "Trace = "
              << A.Trace()
              << "\n\n";

    C = A.Transposed();

    std::cout << "Transpose\n";
    std::cout << C.m00 << " " << C.m01 << "\n";
    std::cout << C.m10 << " " << C.m11 << "\n\n";

    C = A.Inverse();

    std::cout << "Inverse\n";
    std::cout << C.m00 << " " << C.m01 << "\n";
    std::cout << C.m10 << " " << C.m11 << "\n";

    std::cout << "\n========== MathUtils Demo ==========\n\n";

std::cout << "PI = " << Math::PI << '\n';
std::cout << "TWO_PI = " << Math::TWO_PI << '\n';
std::cout << "HALF_PI = " << Math::HALF_PI << "\n\n";

std::cout << "Clamp(15, 0, 10) = "
          << Math::Clamp(15.0f, 0.0f, 10.0f)
          << '\n';

std::cout << "Lerp(0, 100, 0.25) = "
          << Math::Lerp(0.0f, 100.0f, 0.25f)
          << '\n';

std::cout << "Min(3, 7) = "
          << Math::Min(3.0f, 7.0f)
          << '\n';

std::cout << "Max(3, 7) = "
          << Math::Max(3.0f, 7.0f)
          << '\n';

std::cout << "Abs(-42) = "
          << Math::Abs(-42.0f)
          << '\n';

std::cout << "Sign(-10) = "
          << Math::Sign(-10.0f)
          << '\n';

std::cout << "90 Degrees = "
          << Math::DegreesToRadians(90.0f)
          << " radians\n";

std::cout << "PI Radians = "
          << Math::RadiansToDegrees(Math::PI)
          << " degrees\n";

std::cout << "Square(6) = "
          << Math::Square(6.0f)
          << '\n';

std::cout << "Cube(4) = "
          << Math::Cube(4.0f)
          << '\n';

std::cout << "NearlyEqual(1.0, 1.0000001) = "
          << Math::NearlyEqual(1.0f, 1.0000001f)
          << '\n';

std::cout << "IsZero(0.00000001) = "
          << Math::IsZero(0.00000001f)
          << '\n';

std::cout << "IsFinite(42) = "
          << Math::IsFinite(42.0f)
          << '\n';
    std::cout << "\n=========================================================\n";

    std::cout << "\n========== Vec3 Demo ==========\n\n";

Vec3 a(1.0f, 2.0f, 3.0f);
Vec3 b(4.0f, 5.0f, 6.0f);

std::cout << "A = (" << a.x << ", " << a.y << ", " << a.z << ")\n";
std::cout << "B = (" << b.x << ", " << b.y << ", " << b.z << ")\n\n";

// Addition
Vec3 add = a + b;
std::cout << "A + B = ("
          << add.x << ", "
          << add.y << ", "
          << add.z << ")\n";

// Subtraction
Vec3 sub = a - b;
std::cout << "A - B = ("
          << sub.x << ", "
          << sub.y << ", "
          << sub.z << ")\n";

// Scalar Multiplication
Vec3 mul = a * 2.0f;
std::cout << "A * 2 = ("
          << mul.x << ", "
          << mul.y << ", "
          << mul.z << ")\n";

// Scalar Division
Vec3 dived = a / 2.0f;
std::cout << "A / 2 = ("
          << dived.x << ", "
          << dived.y << ", "
          << dived.z << ")\n";

// Length
std::cout << "Length(A) = "
          << a.Length()
          << '\n';

// Dot Product
std::cout << "Dot(A, B) = "
          << a.Dot(b)
          << '\n';

// Cross Product
Vec3 cross = a.Cross(b);

std::cout << "Cross(A, B) = ("
          << cross.x << ", "
          << cross.y << ", "
          << cross.z << ")\n";

// Distance
std::cout << "Distance(A, B) = "
          << a.Distance(b)
          << '\n';

// Normalize
Vec3 norm = a.Normalized();

std::cout << "Normalized A = ("
          << norm.x << ", "
          << norm.y << ", "
          << norm.z << ")\n";

// Zero Vector
Vec3 zero;

std::cout << "Zero Vector? "
          << (zero.IsZero() ? "Yes" : "No")
          << '\n';
    return 0;
}