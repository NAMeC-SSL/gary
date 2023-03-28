#include "motor_manager.h"

MotorManager::MotorManager()
    : driver_spi(SPI_MOSI_DRV, SPI_MISO_DRV, SPI_SCK_DRV),
      frontLeftMotor(BrushlessBoard(&driver_spi, SPI_CS_DRV1)),
      backLeftMotor(BrushlessBoard(&driver_spi, SPI_CS_DRV2)),
      backRightMotor(BrushlessBoard(&driver_spi, SPI_CS_DRV3)),
      frontRightMotor(BrushlessBoard(&driver_spi, SPI_CS_DRV4)) {
    driver_spi.frequency(500000);
}

void MotorManager::stop() {}

void MotorManager::set_speed(MotorSpeed speed) { this->speed = speed; }

void MotorManager::run() {
    frontLeftMotor.set_speed(Commands_RUN, this->speed.front_left);
    frontRightMotor.set_speed(Commands_RUN, this->speed.front_right);
    backLeftMotor.set_speed(Commands_RUN, this->speed.back_left);
    backRightMotor.set_speed(Commands_RUN, this->speed.back_right);
}