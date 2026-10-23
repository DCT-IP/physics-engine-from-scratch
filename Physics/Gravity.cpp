#include "Gravity.h"
#include "Body.h"

Gravity::Gravity(const Math::Vec2& gravity)
    : gravity(gravity)
{
}

void Gravity::apply(Body& body)
{
    const Math::Vec2 force = gravity * body.getMass();
    body.applyForce(force);
}