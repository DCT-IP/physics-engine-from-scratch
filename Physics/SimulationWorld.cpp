#include "SimulationWorld.h"
#include <stdexcept>
#include <utility>
#include "Body.h"

SimulationWorld::SimulationWorld(
    float fixedDeltaTime,
    std::size_t maxSubsteps
)
    : fixedTimestep(fixedDeltaTime, maxSubsteps)
{
}

Body& SimulationWorld::addBody(std::unique_ptr<Body> body)
{
    return bodySystem.addBody(std::move(body));
}

void SimulationWorld::addForceGenerator(
    Body& body,
    std::unique_ptr<ForceGenerator> generator
)
{
    if (!generator) {
        throw std::invalid_argument(
            "Force generator cannot be null"
        );
    }
    ForceGenerator* generatorPtr = generator.get();
    forceGenerators.push_back(std::move(generator));
    try {
        bodySystem.addForceGenerator(body, *generatorPtr);
    }
    catch (...) {
        forceGenerators.pop_back();
        throw;
    }
}

std::size_t SimulationWorld::advance(float frameDeltaTime)
{
    return fixedTimestep.advance(
        frameDeltaTime,
        [this](float dt) {
            bodySystem.update(dt);
        }
    );
}

void SimulationWorld::resetTime()
{
    fixedTimestep.reset();
}

std::size_t SimulationWorld::getBodyCount() const
{
    return bodySystem.getBodyCount();
}

float SimulationWorld::getFixedDeltaTime() const
{
    return fixedTimestep.getFixedDeltaTime();
}

float SimulationWorld::getAccumulator() const
{
    return fixedTimestep.getAccumulator();
}
