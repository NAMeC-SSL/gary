#pragma once
#include <brushless.pb.h>
#include <mbed.h>
#include <pb.h>
#include <pb_decode.h>
#include <pb_encode.h>

#define HEADER_SIZE 5  // 4 + 1

class BrushlessBoard {
   public:
    BrushlessBoard(SPI *spi, PinName chip_select);

    void set_speed(Commands command, float speed);

   private:
    DigitalOut _chip_select;
    SPI *_spi;

    uint8_t _brushless_tx_buffer[RobotToBrushless_size + HEADER_SIZE];
    uint8_t _brushless_rx_buffer[BrushlessToRobot_size + HEADER_SIZE];
};