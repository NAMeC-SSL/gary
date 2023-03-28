#include <mbed.h>
#include <swo.h>

#include "motor/motor_manager.h"
#include "sensor/ir.h"

#define BLINKING_RATE 30ms
static SWO swo;

FileHandle *mbed::mbed_override_console(int fd) { return &swo; }

DigitalOut led(LED1);

EventQueue event_queue;

int main() {
    MotorManager m;
    MotorSpeed speed;
    speed.back_left = 0.5;
    speed.back_right = 0.5;
    speed.front_left = 0.5;
    speed.front_right = 0.5;
    m.set_speed(speed);

    while (true) {
        led = !led;
        m.run();
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
