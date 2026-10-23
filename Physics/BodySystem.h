#pragma once
#include <memory>
#include <vector>
#include "Body.h"
#include "ForceGenerator.h"
#include "SemiImplicitEuler.h"

class BodySystem
{
public:
    Body& addBody(std::unique_ptr<Body> body);
    void addForceGenerator(
        Body& body,
        ForceGenerator& generator
    );
    void update(float dt);
    std::size_t getBodyCount() const;

private:
    struct ForceRegistration {
        Body* body;
        ForceGenerator* generator;
    };
    bool containsBody(const Body* body) const;
    std::vector<std::unique_ptr<Body>> bodies;
    std::vector<ForceRegistration> forceRegistrations;

    SemiImplicitEuler integrator;
};