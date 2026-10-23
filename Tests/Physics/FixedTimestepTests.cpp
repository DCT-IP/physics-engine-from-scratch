#include "../../Physics/FixedTimestep.h"
#include <cassert>
#include <cmath>
#include <stdexcept>

bool nearlyEqual(float a, float b,
                 float epsilon = 0.0001f)
{
    return std::fabs(a - b) < epsilon;
}

void testInitialState()
{
    FixedTimestep timestep(0.1f);
    assert(nearlyEqual(timestep.getFixedDeltaTime(), 0.1f));
    assert(nearlyEqual(timestep.getAccumulator(), 0.0f));
}

void testNoUpdateBeforeFullStep()
{
    FixedTimestep timestep(0.1f);
    int updates = 0;
    const auto steps = timestep.advance(
        0.05f,
        [&](float dt) {
            assert(nearlyEqual(dt, 0.1f));
            ++updates;
        }
    );
    assert(steps == 0);
    assert(updates == 0);
    assert(nearlyEqual(timestep.getAccumulator(), 0.05f));
}

void testSingleFixedStep()
{
    FixedTimestep timestep(0.1f);
    int updates = 0;
    const auto steps = timestep.advance(
        0.1f,
        [&](float dt) {
            assert(nearlyEqual(dt, 0.1f));
            ++updates;
        }
    );
    assert(steps == 1);
    assert(updates == 1);
    assert(nearlyEqual(timestep.getAccumulator(), 0.0f));
}

void testMultipleFixedSteps()
{
    FixedTimestep timestep(0.1f);
    int updates = 0;
    const auto steps = timestep.advance(
        0.35f,
        [&](float) {
            ++updates;
        }
    );
    assert(steps == 3);
    assert(updates == 3);
    assert(nearlyEqual(timestep.getAccumulator(), 0.05f));
}

void testMaximumSubsteps()
{
    FixedTimestep timestep(0.1f, 2);
    int updates = 0;
    const auto steps = timestep.advance(
        0.55f,
        [&](float) {
            ++updates;
        }
    );
    assert(steps == 2);
    assert(updates == 2);
    assert(nearlyEqual(timestep.getAccumulator(), 0.05f));
}

void testZeroFrameDelta()
{
    FixedTimestep timestep(0.1f);
    const auto steps = timestep.advance(
        0.0f,
        [](float) {}
    );
    assert(steps == 0);
}

void testReset()
{
    FixedTimestep timestep(0.1f);
    timestep.advance(0.05f, [](float) {});
    timestep.reset();
    assert(nearlyEqual(timestep.getAccumulator(), 0.0f));
}

void testInvalidInputs()
{
    bool invalidStepRejected = false;
    try {
        FixedTimestep timestep(0.0f);
    }
    catch (const std::invalid_argument&) {
        invalidStepRejected = true;
    }
    assert(invalidStepRejected);
    FixedTimestep timestep(0.1f);
    bool invalidFrameRejected = false;
    try {
        timestep.advance(-0.1f, [](float) {});
    }
    catch (const std::invalid_argument&) {
        invalidFrameRejected = true;
    }
    assert(invalidFrameRejected);
}

int main()
{
    testInitialState();
    testNoUpdateBeforeFullStep();
    testSingleFixedStep();
    testMultipleFixedSteps();
    testMaximumSubsteps();
    testZeroFrameDelta();
    testReset();
    testInvalidInputs();

    return 0;
}