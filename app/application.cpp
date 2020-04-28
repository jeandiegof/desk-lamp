#include <Libraries/WS2812/WS2812.h>

#include <SmingCore.h>

#define LED_PIN 15

Timer timer;

void change_color()
{
    static bool _state = true;

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
	timer.initializeMs(1000, change_color).start();
}
