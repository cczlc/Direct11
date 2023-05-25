#include "ChiliTimer.h"
// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

using namespace std::chrono;

TimerClock::TimerClock() noexcept {
    update();
}

void TimerClock::update() noexcept {
    mStart = high_resolution_clock::now();
}

double TimerClock::getSecond() noexcept {
    return getMicroSecond() * 0.000001;
}

double TimerClock::getMilliSecond() noexcept {
    return getMicroSecond() * 0.001;
}

double TimerClock::getMicroSecond() noexcept {
    return duration_cast<microseconds>(high_resolution_clock::now() - mStart).count();
}
