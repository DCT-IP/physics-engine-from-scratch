#include "Body.h"

Body::Body(const Math::Vec2& position, float mass)
    : position(position),
      velocity(0.0f, 0.0f),
      acceleration(0.0f, 0.0f),
      forceAccumulator(0.0f, 0.0f),
      mass(mass)
{
    if (mass != 0.0f) {
        inverseMass = 1.0f / mass;
    } else {
        inverseMass = 0.0f;
    }
}
void Body::applyForce(const Math::Vec2& force)
{
    forceAccumulator += force;
}
void Body::Integrate(float deltaTime)
{
    if (inverseMass == 0.0f) return; 
    acceleration = forceAccumulator * inverseMass;
    velocity += acceleration * deltaTime;
    position += velocity * deltaTime;
    clearForces();
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

