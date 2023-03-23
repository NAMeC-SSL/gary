#include <swo.h>

#include "mbed.h"
#include "sensor/ir.h"

#define BLINKING_RATE 16ms
static SWO swo;

DigitalOut led(LED1);

int main() {
    while (true) {
        led = !led;
        swo.println("Hello, World!");
        ir::compute();
        swo.println(ir::present());
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
