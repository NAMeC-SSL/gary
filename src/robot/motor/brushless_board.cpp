#include "brushless_board.h"

BrushlessBoard::BrushlessBoard(SPI *spi, PinName chip_select)
    : _chip_select(chip_select), _spi(spi) {}

void BrushlessBoard::set_speed(Commands command, float speed) {
    RobotToBrushless msg = RobotToBrushless_init_zero;
    memset(_brushless_tx_buffer, 0, sizeof(_brushless_tx_buffer));

    pb_ostream_t tx_stream = pb_ostream_from_buffer(
        _brushless_tx_buffer + HEADER_SIZE, RobotToBrushless_size);

    msg.command = command;
    msg.speed = speed;

    bool status = pb_encode(&tx_stream, RobotToBrushless_fields, &msg);
    size_t message_length = tx_stream.bytes_written;

    printf("Bytes_written: %d/%d\n", tx_stream.bytes_written,
           BrushlessToRobot_size);
    for (int i = 0; i < tx_stream.bytes_written; i++) {
        printf("%x ", _brushless_tx_buffer[4 + i]);
    }
    printf("\n");

    if (!status) {
        printf("[BRUSHLESS] Encoding failed: %s\n", PB_GET_ERROR(&tx_stream));
        return;
    }

    MbedCRC<POLY_32BIT_ANSI, 32> ct;
    ct.compute((uint8_t *)_brushless_tx_buffer + HEADER_SIZE, message_length,
               (uint32_t *)(_brushless_tx_buffer + 1));
    _brushless_tx_buffer[0] = message_length;

    _chip_select = 0;
    _spi->write((const char *)_brushless_tx_buffer,
                message_length + HEADER_SIZE, (char *)_brushless_rx_buffer,
                BrushlessToRobot_size + HEADER_SIZE);

    _chip_select = 1;

    BrushlessToRobot response = BrushlessToRobot_init_zero;
    uint8_t response_length = _brushless_rx_buffer[0];

    /* Create a stream that reads from the buffer. */
    pb_istream_t rx_stream = pb_istream_from_buffer(
        _brushless_rx_buffer + HEADER_SIZE, response_length);

    /* Now we are ready to decode the message. */
    status = pb_decode(&rx_stream, BrushlessToRobot_fields, &response);

    /* Check for errors... */
    if (!status) {
        printf("[BRUSHLESS] Decoding failed: %s\n", PB_GET_ERROR(&rx_stream));
        //_rx_error_count++;
        return;
    }

    /* Check response CRC */
    uint32_t response_crc = 0;
    ct.compute((uint8_t *)_brushless_rx_buffer + 5, response_length,
               &response_crc);
    if (response_crc == *((uint32_t *)(_brushless_rx_buffer + 1))) {
        printf("CRC OK\n");
    } else {
        printf("CRC_ERROR 0x%x 0x%x\n", response_crc,
               *((uint32_t *)(_brushless_rx_buffer + 1)));
        //_rx_error_count++;
        return;
    }

    /* Print the data contained in the message. */
    //_tx_error_count = response.error_count;
}