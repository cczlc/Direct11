#ifndef CPP11TIMER_TIMERCLOCK_H
#define CPP11TIMER_TIMERCLOCK_H

#include <chrono>

class TimerClock {
public:
    TimerClock() noexcept;
    virtual ~TimerClock() = default;
    void update() noexcept;
    double getSecond() noexcept;
    double getMilliSecond() noexcept;
    double getMicroSecond() noexcept;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> mStart;
};


#endif //CPP11TIMER_TIMERCLOCK_H