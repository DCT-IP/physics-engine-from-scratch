#include "FixedTimestep.h"
#include <cmath>
#include <stdexcept>

FixedTimestep::FixedTimestep(
    float fixedDeltaTime,
    std::size_t maxSubsteps
)
    : fixedDeltaTime(fixedDeltaTime),
      accumulator(0.0f),
      maxSubsteps(maxSubsteps)
{
    if (!std::isfinite(fixedDeltaTime) ||
        fixedDeltaTime <= 0.0f) {
        throw std::invalid_argument(
            "Fixed timestep must be finite and positive"
        );
    }
    if (maxSubsteps == 0) {
        throw std::invalid_argument(
            "Maximum substeps must be greater than zero"
        );
    }
}

std::size_t FixedTimestep::advance(
    float frameDeltaTime,
    const std::function<void(float)>& update
)
{
    if (!std::isfinite(frameDeltaTime) ||
        frameDeltaTime < 0.0f) {
        throw std::invalid_argument(
            "Frame timestep must be finite and non-negative"
        );
    }
    if (!update) {
        throw std::invalid_argument(
            "Update callback must be valid"
        );
    }
    accumulator += frameDeltaTime;
    std::size_t steps = 0;
    while (accumulator >= fixedDeltaTime &&
           steps < maxSubsteps) {
        update(fixedDeltaTime);
        accumulator -= fixedDeltaTime;
        ++steps;
    }

    if (steps == maxSubsteps &&
        accumulator >= fixedDeltaTime) {
        accumulator = std::fmod(
            accumulator,
            fixedDeltaTime
        );
    }
    return steps;
}

void FixedTimestep::reset()
{
    accumulator = 0.0f;
}

float FixedTimestep::getFixedDeltaTime() const
{
    return fixedDeltaTime;
}

float FixedTimestep::getAccumulator() const
{
    return accumulator;
}

std::size_t FixedTimestep::getMaxSubsteps() const
{
    return maxSubsteps;
}