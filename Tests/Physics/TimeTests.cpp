#include "../../Core/Time/Time.h"
#include <cassert>
#include <chrono>
#include <thread>

void testInitialTimeIsZero()
{
    Time time;

    assert(time.getDeltaTime() == 0.0f);
    assert(time.getElapsedTime() == 0.0f);
}

void testTickUpdatesElapsedTime()
{
    Time time;

    std::this_thread::sleep_for(
        std::chrono::milliseconds(10)
    );

    time.tick();

    assert(time.getDeltaTime() > 0.0f);
    assert(time.getElapsedTime() > 0.0f);
}

void testElapsedTimeDoesNotDecrease()
{
    Time time;

    time.tick();
    const float firstElapsed = time.getElapsedTime();

    std::this_thread::sleep_for(
        std::chrono::milliseconds(5)
    );

    time.tick();

    assert(time.getElapsedTime() >= firstElapsed);
}

void testReset()
{
    Time time;

    std::this_thread::sleep_for(
        std::chrono::milliseconds(5)
    );

    time.tick();
    time.reset();

    assert(time.getDeltaTime() == 0.0f);
    assert(time.getElapsedTime() == 0.0f);
}

int main()
{
    testInitialTimeIsZero();
    testTickUpdatesElapsedTime();
    testElapsedTimeDoesNotDecrease();
    testReset();

    return 0;
}