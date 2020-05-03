#include "ws2812/led.hpp"
#include "ws2812/strip.hpp"

#include <Libraries/WS2812/WS2812.h>

#include <SmingCore.h>

#define LED_PIN 15

Timer timer;

void change_color()
{
    static bool _state = true;

    ws2812::led led;
    led.print();
    Serial.printf("sizeof led: %d", sizeof(led));

    ws2812::led led2(_state, !_state, 3);
    led2.print();
    Serial.printf("sizeof led2: %d", sizeof(led2));

    ws2812::strip strip(10);
    strip.print();
    Serial.printf("sizeof strip: %d", sizeof(strip));

    if (_state) {
        char buffer[] = "\xff\x00\x00\x00\xff\x00\x00\x00\xff";
        ws2812_writergb(LED_PIN, buffer, sizeof(buffer));
    } else {
        char buffer[] = "\x20\x00\x00\x00\x20\x00\x00\x00\x20";
        ws2812_writergb(LED_PIN, buffer, sizeof(buffer));
    }

    _state = !_state;
}

void init()
{
    Serial.begin(115200);
    Serial.systemDebugOutput(false);
    system_set_os_print(0);

    timer.initializeMs(1000, change_color).start();
}
