#pragma once

#include "ws2812/strip.hpp"
#include "ws2812/led.hpp"

#include <vector>

namespace ws2812 {

class strip {
    public:
        strip(uint8_t n_leds) : _leds{n_leds} {};

        void print() {
            std::for_each(_leds.begin(), _leds.end(), [](led i) { i.print(); });
        }

    private:
        std::vector<led> _leds;
};
}
