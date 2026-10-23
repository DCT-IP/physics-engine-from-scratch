#include "ConstantForce.h"
#include "Body.h"
ConstantForce::ConstantForce(const Math::Vec2& force)
    : force(force)
{
}
void ConstantForce::apply(Body& body)
{
    body.applyForce(force);
}
