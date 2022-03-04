#ifndef CLOCK_H
#define CLOCK_H

#include "../headers.h"

// This file contains class used to roughly measure time spent in scope where class instance is created on the stack.
// Otherwise behaviour if undefined.

class Clock {
private:
    using clock_type = std::chrono::high_resolution_clock;
    using time_type = std::chrono::_V2::system_clock::time_point;

    const time_type timer_start;
    const std::string name;

public:
    Clock(const std::string& text) : timer_start(clock_type::now()), name(text) { /*void */ };
    Clock() : timer_start(clock_type::now()), name("unknown") { /*void */ };

    ~Clock() {
        auto timer_stop = clock_type::now();
        auto result = std::chrono::duration_cast<std::chrono::microseconds>(timer_stop - timer_start);
        DATATYPE result_microseconds = result.count();
        std::cout << "This " << name << " took \n";
        std::cout << result.count() << " microseconds\n";
        std::cout << std::fixed << std::setprecision(3) << result_microseconds / 1000 << " milliseconds\n";
        std::cout << std::fixed << std::setprecision(3) << result_microseconds / 1e6 << " seconds" << std::endl;

    }
};


#endif