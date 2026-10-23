// a common interface to allow other integration methods later without changing the sim architecture
#pragma once
class Body;
class Integrator
{
    public: 
        virtual ~Integrator() = default;
        virtual void integrate(Body& body, float dt) = 0;
};
