#pragma once

#include "Vec2.h"

class Body
{
public:
    Body(const Math::Vec2& position, float mass);

    void applyForce(const Math::Vec2& force);
    void Integrate(float dt);
    void clearForces();

    const Math::Vec2& getPosition() const;
    const Math::Vec2& getVelocity() const;

    float getMass() const;
    float getInverseMass() const;

private:
    Math::Vec2 position;
    Math::Vec2 velocity;
    Math::Vec2 acceleration;
    Math::Vec2 forceAccumulator;

    float mass;
    float inverseMass;
};