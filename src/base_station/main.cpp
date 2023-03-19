#include "mbed.h"
#include <swo.h>

#include "pb.h"
#include "pb_decode.h"
#include "pb_encode.h"
#include "ssl_data.pb.h"

#define BLINKING_RATE 500ms
static SWO swo;

EventQueue event_queue;
DigitalOut led(LED1);
static UnbufferedSerial serial_port(USBTX, USBRX);
static uint8_t radio_packet[IAToMainBoard_size + 1];
static IAToMainBoard ai_message = IAToMainBoard_init_zero;

FileHandle *mbed::mbed_override_console(int fd)
{
    return &swo;
}


void on_rx_interrupt()
{
    static bool start_of_frame = false;
    static uint8_t length = 0;
    static uint8_t read_count = 0;
    static uint8_t read_buffer[IAToMainBoard_size];
    uint8_t c;

    if (!start_of_frame) {
        serial_port.read(&c, 1);
        if (c > 0 && c <= (IAToMainBoard_size)) { // Get packet length
            start_of_frame = true;
            length = c;
            read_count = 0;
            // event_queue.call(printf, "Receiving : %d\n", length);
        } else if (c == 0) { // When length is 0 it is the default protobuf packet
            start_of_frame = false;
            length = 0;
            read_count = 0;
            radio_packet[0] = 0;
            // event_queue.call(send_protobuf_packet);
        }
    } else {
        serial_port.read(&read_buffer[read_count], 1);
        read_count++;
        if (read_count == length) {
            read_count = 0;
            start_of_frame = false;

            // event_queue.call(printf, "Parsing !\n");

            /* Try to decode protobuf response */
            ai_message = IAToMainBoard_init_zero;

            /* Create a stream that reads from the buffer. */
            pb_istream_t rx_stream = pb_istream_from_buffer(read_buffer, length);

            /* Now we are ready to decode the message. */
            bool status = pb_decode(&rx_stream, IAToMainBoard_fields, &ai_message);

            /* Check for errors... */
            if (!status) {
                event_queue.call(printf, "Decoding failed: %s\n", PB_GET_ERROR(&rx_stream));
            } else {
                radio_packet[0] = length;
                memcpy(&radio_packet[1], read_buffer, length);
                event_queue.call(printf, "CMD! Length: %d\n", length);
                // event_queue.call(send_protobuf_packet);
            }
        }
    }
}


int main() {
    serial_port.baud(115200);
    serial_port.attach(&on_rx_interrupt, SerialBase::RxIrq);
    event_queue.dispatch_forever();
    
    while (true) {
        led = !led;
        swo.println("Alive!");
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
