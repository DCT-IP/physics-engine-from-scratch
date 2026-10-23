#include "SemiImplicitEuler.h"
#include "Body.h"
#include <cmath>
#include <stdexcept>

void SemiImplicitEuler::integrate(Body& body, float dt)
{
    if (!std::isfinite(dt) || dt < 0.0f) {
        throw std::invalid_argument(
            "Timestep must be finite and non-negative"
        );
    }
    if (body.inverseMass == 0.0f) {
        body.clearForces();
        return;
    }
    body.acceleration = body.forceAccumulator * body.inverseMass;
    body.velocity += body.acceleration * dt;
    body.position += body.velocity * dt;
    body.clearForces();
}
