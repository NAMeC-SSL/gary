#pragma once

#include <mbed.h>

#include "brushless_board.h";

typedef struct {
    float front_left;
    float front_right;
    float back_left;
    float back_right;
} MotorSpeed;

class MotorManager {
   public:
    MotorManager();
    void set_speed(MotorSpeed speed);
    void run();
    void stop();

   private:
    SPI driver_spi;
    BrushlessBoard frontLeftMotor;
    BrushlessBoard frontRightMotor;
    BrushlessBoard backLeftMotor;
    BrushlessBoard backRightMotor;
    MotorSpeed speed;
};