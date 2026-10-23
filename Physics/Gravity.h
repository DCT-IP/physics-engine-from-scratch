#pragma once
#include "ForceGenerator.h"
#include "Vec2.h"

class Gravity : public ForceGenerator {
public:
    explicit Gravity(const Math::Vec2& gravity);
    void apply(Body& body) override;
private:
    Math::Vec2 gravity;
};
