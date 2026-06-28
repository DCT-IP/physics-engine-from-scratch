#include "../Core/Math/Vec2.h"

#include <cassert>
#include <cmath>
#include <iostream>

int main()
{
    
    Vec2 a;
    assert(a.x == 0.0f);
    assert(a.y == 0.0f);

    Vec2 b(3.0f, 4.0f);
    assert(b.x == 3.0f);
    assert(b.y == 4.0f);


    Vec2 c = a + b;
    assert(c.x == 3.0f);
    assert(c.y == 4.0f);


    Vec2 d = b - Vec2(1.0f, 2.0f);
    assert(d.x == 2.0f);
    assert(d.y == 2.0f);


    Vec2 e = b * 2.0f;
    assert(e.x == 6.0f);
    assert(e.y == 8.0f);

    Vec2 f = e / 2.0f;
    assert(f == b);


    Vec2 g(1.0f, 1.0f);

    g += Vec2(2.0f, 3.0f);
    assert(g == Vec2(3.0f, 4.0f));

    g -= Vec2(1.0f, 1.0f);
    assert(g == Vec2(2.0f, 3.0f));

    g *= 2.0f;
    assert(g == Vec2(4.0f, 6.0f));

    g /= 2.0f;
    assert(g == Vec2(2.0f, 3.0f));

    Vec2 h = -g;
    assert(h == Vec2(-2.0f, -3.0f));


    assert(std::abs(b.Length() - 5.0f) < 1e-6f);
    assert(b.LengthSquared() == 25.0f);


    Vec2 n(3.0f, 4.0f);
    n.Normalize();

    assert(std::abs(n.Length() - 1.0f) < 1e-6f);

    Vec2 n2 = b.Normalized();

    assert(std::abs(n2.Length() - 1.0f) < 1e-6f);

    Vec2 xAxis(1.0f, 0.0f);

    assert(b.Dot(xAxis) == 3.0f);


    Vec2 p1(0.0f, 0.0f);
    Vec2 p2(3.0f, 4.0f);

    assert(std::abs(p1.Distance(p2) - 5.0f) < 1e-6f);
    assert(p1.DistanceSquared(p2) == 25.0f);

    Vec2 perp = xAxis.Perpendicular();
    assert(perp == Vec2(0.0f, 1.0f));


    Vec2 proj = Vec2(2.0f, 2.0f).Project(xAxis);
    assert(proj == Vec2(2.0f, 0.0f));


    Vec2 incoming(1.0f, -1.0f);
    Vec2 normal(0.0f, 1.0f);
    Vec2 reflected = incoming.Reflect(normal);
    assert(reflected == Vec2(1.0f, 1.0f));

    assert(Vec2().IsZero());
    assert(!b.IsZero());
    std::cout << "=====================================\n";
    std::cout << " All Vec2 tests passed successfully!\n";
    std::cout << "=====================================\n";

    return 0;
}