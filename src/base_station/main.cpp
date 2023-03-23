#include <swo.h>

#include "mbed.h"

#define BLINKING_RATE 500ms
static SWO swo;

DigitalOut led(LED1);

int main() {
    while (true) {
        led = !led;
        swo.println("Hello, World!");
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
