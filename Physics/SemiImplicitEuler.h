#pragma once
#include "Integrator.h"

class SemiImplicitEuler : public Integrator
{
public:
    void integrate(Body& body, float dt) override;
};