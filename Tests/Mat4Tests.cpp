#include "../Core/Math/Mat4.h"
#include <cassert>
#include <iostream>

using namespace Math;

int main()
{
    Mat4 zero;
    assert(zero == Mat4());

    Mat4 I = Mat4::Identity();

    assert(I.m00==1);
    assert(I.m11==1);
    assert(I.m22==1);
    assert(I.m33==1);

    Mat4 A(
        1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,14,15,16
    );

    Mat4 B(
        16,15,14,13,
        12,11,10,9,
        8,7,6,5,
        4,3,2,1
    );

    assert((A+B).m00==17);
    assert((A-B).m00==-15);

    assert((A*2).m00==2);
    assert(((A*2)/2)==A);

    Mat4 temp=A;
    temp+=B;
    assert(temp==A+B);

    temp=A;
    temp-=B;
    assert(temp==A-B);

    temp=A;
    temp*=2;
    assert(temp==A*2);

    temp/=2;
    assert(temp==A);

    Mat4 T=A.Transpose();

    assert(T.m01==5);
    assert(T.m10==2);

    Vec4 v(1,2,3,1);

    assert(I*v==v);

    assert((A*I)==A);

    // TODO
    // Determinant tests

    // TODO
    // Inverse tests

    std::cout<<"All Mat4 tests passed.\n";
}