#pragma once
#include <cstddef>
#include <memory>
#include <vector>
#include "BodySystem.h"
#include "FixedTimestep.h"
#include "ForceGenerator.h"
class Body;
class SimulationWorld {
public:
    explicit SimulationWorld(
        float fixedDeltaTime = 1.0f / 60.0f,
        std::size_t maxSubsteps = 8
    );
    Body& addBody(std::unique_ptr<Body> body);
    void addForceGenerator(
        Body& body,
        std::unique_ptr<ForceGenerator> generator
    );
    std::size_t advance(float frameDeltaTime);
    void resetTime();
    std::size_t getBodyCount() const;
    float getFixedDeltaTime() const;
    float getAccumulator() const;
private:
    std::vector<std::unique_ptr<ForceGenerator>> forceGenerators;
    BodySystem bodySystem;
    FixedTimestep fixedTimestep;
};
