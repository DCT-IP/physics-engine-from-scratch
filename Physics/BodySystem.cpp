#include "BodySystem.h"
#include <stdexcept>

Body& BodySystem::addBody(std::unique_ptr<Body> body)
{
    if(!body){
        throw std::invalid_argument("Cannot add a null body");
    }
    Body& refrn = *body;
    bodies.push_back(std::move(body));
    return refrn;
}

void BodySystem::addForceGenerator(
    Body& body,
    ForceGenerator& generator
)
{
    if(!containsBody(&body))
    {
        throw std::invalid_argument(
            "cannot register a force generator for an unmanaged body"
        );
    }
    forceRegistrations.push_back({&body,&generator});
}

void BodySystem::update(float dt)
{
    for (const auto& registration : forceRegistrations) {
        registration.generator->apply(*registration.body);
    }
    for (const auto& body : bodies) {
        integrator.integrate(*body, dt);
    }
}

std::size_t BodySystem::getBodyCount() const {
    return bodies.size();
}

bool BodySystem::containsBody(const Body* body) const
{
    for (const auto& ownedBody : bodies) { 
        if (ownedBody.get() == body){
            return true;
        }
    }
    return false;
}