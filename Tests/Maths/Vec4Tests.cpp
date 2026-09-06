#include <cassert>
#include <iostream>

#include "Vec4.h"

using namespace Math;

int main()
{
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
}