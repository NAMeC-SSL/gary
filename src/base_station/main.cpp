#include "mbed.h"
#include <swo.h>

#define BLINKING_RATE 500ms
static swo::SWO swo_st;

DigitalOut led(LED1);

int main() {
    while (true) {
        led = !led;
        swo_st.println("Hello, World!");
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
