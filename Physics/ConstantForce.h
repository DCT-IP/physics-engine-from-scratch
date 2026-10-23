#pragma once
#include "ForceGenerator.h"
#include "Vec2.h"
class ConstantForce : public ForceGenerator {
public:
    explicit ConstantForce(const Math::Vec2& force);
    void apply(Body& body) override;
private:
    Math::Vec2 force;
};
