#pragma once

#include <cstdint>

#include <SmingCore.h>

namespace ws2812 {

class led {
    public:
        led(void) : _r{0}, _g{0}, _b{0} {}
        led(uint8_t r, uint8_t g, uint8_t b) : _r{r}, _g{g}, _b{b} {}

        void print() { Serial.printf("rgb(%d, %d, %d)\n", _r, _g, _b); }

    private:
        uint8_t _r;
        uint8_t _g;
        uint8_t _b;
};
}
