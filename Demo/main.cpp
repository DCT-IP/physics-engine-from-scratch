#include <iostream>

#include "../Core/Math/Vec2.h"
#include "../Core/Math/Mat2.h"

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

    std::cout << "\n=========================================================\n";
    return 0;
}