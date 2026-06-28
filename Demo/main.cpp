#include "../Core/Math/Vec2.h"

#include <iostream>

int main()
{
    std::cout << "========== Vec2 Demonstration ==========\n\n";

    Vec2 a(3.0f, 4.0f);
    Vec2 b(1.0f, 2.0f);

    std::cout << "Vector A : (" << a.x << ", " << a.y << ")\n";
    std::cout << "Vector B : (" << b.x << ", " << b.y << ")\n\n";

    // Addition

    Vec2 add = a + b;

    std::cout << "A + B = ("
              << add.x << ", "
              << add.y << ")\n";

    // Subtraction

    Vec2 sub = a - b;

    std::cout << "A - B = ("
              << sub.x << ", "
              << sub.y << ")\n";

    // Scalar Multiplication

    Vec2 mul = a * 2.0f;

    std::cout << "A * 2 = ("
              << mul.x << ", "
              << mul.y << ")\n";

    // Scalar Division

    Vec2 div = a / 2.0f;

    std::cout << "A / 2 = ("
              << div.x << ", "
              << div.y << ")\n\n";

    // Length

    std::cout << "Length of A = "
              << a.Length() << '\n';

    std::cout << "Length Squared of A = "
              << a.LengthSquared() << "\n\n";

    // Normalization

    Vec2 unit = a.Normalized();

    std::cout << "Normalized A = ("
              << unit.x << ", "
              << unit.y << ")\n";

    std::cout << "Length = "
              << unit.Length() << "\n\n";

    // Dot Product

    std::cout << "Dot(A, B) = "
              << a.Dot(b) << "\n\n";

    // Distance

    std::cout << "Distance(A, B) = "
              << a.Distance(b) << "\n\n";

    // Perpendicular

    Vec2 perp = a.Perpendicular();

    std::cout << "Perpendicular of A = ("
              << perp.x << ", "
              << perp.y << ")\n\n";

    // Projection

    Vec2 proj = a.Project(b);

    std::cout << "Projection of A onto B = ("
              << proj.x << ", "
              << proj.y << ")\n\n";

    // Reflection

    Vec2 reflected = Vec2(1.0f, -1.0f).Reflect(Vec2(0.0f, 1.0f));

    std::cout << "Reflection of (1,-1) about Y normal = ("
              << reflected.x << ", "
              << reflected.y << ")\n";

    std::cout << "\n========================================\n";
    std::cout << "Vec2 module demonstration completed.\n";
    std::cout << "========================================\n";

    return 0;
}