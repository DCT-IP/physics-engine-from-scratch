#pragma once
#include <cstddef>
#include <functional>

class FixedTimestep {
public:
    explicit FixedTimestep(
        float fixedDeltaTime = 1.0f / 60.0f,
        std::size_t maxSubsteps = 8
    );
    std::size_t advance(
        float frameDeltaTime,
        const std::function<void(float)>& update
    );
    void reset();
    float getFixedDeltaTime() const;
    float getAccumulator() const;
    std::size_t getMaxSubsteps() const;
private:
    float fixedDeltaTime;
    float accumulator;
    std::size_t maxSubsteps;
};