#include "Body.h"
#include <cmath>
#include <stdexcept>

Body::Body(const Math::Vec2& position, float mass)
    : position(position),
      velocity(0.0f, 0.0f),
      acceleration(0.0f, 0.0f),
      forceAccumulator(0.0f, 0.0f),
      mass(mass),
      inverseMass(0.0f)
{
    if (!std::isfinite(mass) || mass < 0.0f) {
        throw std::invalid_argument(
            "Body mass must be finite and non-negative"
        );
    }

    if (mass > 0.0f) {
        inverseMass = 1.0f / mass;
    }
}

void Body::applyForce(const Math::Vec2& force)
{
    forceAccumulator += force;
}
void Body::clearForces()
{
    forceAccumulator = Math::Vec2(0.0f, 0.0f);
}
const Math::Vec2& Body::getPosition() const
{
    return position;
}
const Math::Vec2& Body::getVelocity() const
{
    return velocity;
}
const Math::Vec2& Body::getAcceleration() const{
    return acceleration;
}
float Body::getMass() const
{
    return mass;
}
float Body::getInverseMass() const
{
    return inverseMass;
}

