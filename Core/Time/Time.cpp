#include "Time.h"

Time::Time()
    : startTime(Clock::now()),
      previousTime(startTime),
      deltaTime(0.0f),
      elapsedTime(0.0f)
{
}

void Time::tick()
{
    const auto currentTime = Clock::now();
    deltaTime = std::chrono::duration<float>(
        currentTime - previousTime
    ).count();
    elapsedTime = std::chrono::duration<float>(
        currentTime - startTime
    ).count();
    previousTime = currentTime;
}

void Time::reset()
{
    startTime = Clock::now();
    previousTime = startTime;
    deltaTime = 0.0f;
    elapsedTime = 0.0f;
}

float Time::getDeltaTime() const
{
    return deltaTime;
}

float Time::getElapsedTime() const
{
    return elapsedTime;
}