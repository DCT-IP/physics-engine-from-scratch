#pragma once
#include <chrono>

class Time {
public:
    Time();
    void tick();
    void reset();
    float getDeltaTime() const;
    float getElapsedTime() const;

private:
    using Clock = std::chrono::steady_clock;
    Clock::time_point startTime;
    Clock::time_point previousTime;
    float deltaTime;
    float elapsedTime;
};