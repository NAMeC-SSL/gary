#include <mbed.h>
#include <swo.h>

// #include "motor/motor_manager.h"
#include "motor/brushless_board.h"
#include "sensor/ir.h"

#define BLINKING_RATE 30ms
#define ROBOT_RADIUS 0.085
static SWO swo;

FileHandle *mbed::mbed_override_console(int fd) { return &swo; }

DigitalOut led(LED1);

EventQueue event_queue;

static SPI driver_spi(SPI_MOSI_DRV, SPI_MISO_DRV, SPI_SCK_DRV);
static Mutex spi_mutex;
static Brushless_board motor1(&driver_spi, SPI_CS_DRV1, &spi_mutex);
static Brushless_board motor2(&driver_spi, SPI_CS_DRV2, &spi_mutex);
static Brushless_board motor3(&driver_spi, SPI_CS_DRV3, &spi_mutex);
static Brushless_board motor4(&driver_spi, SPI_CS_DRV4, &spi_mutex);

/* Struct definitions */
typedef struct _Motor_speed {
    float speed1;
    float speed2;
    float speed3;
    float speed4;
} Motor_speed;

void compute_motor_speed(Motor_speed *motor_speed, float normal_speed,
                         float tangential_speed, float angular_speed) {
    motor_speed->speed1 = -(sqrt(3) / 2.) * normal_speed +
                          (1. / 2.) * tangential_speed +
                          ROBOT_RADIUS * angular_speed;
    motor_speed->speed2 = -(sqrt(2) / 2.) * normal_speed -
                          (sqrt(2) / 2.) * tangential_speed +
                          ROBOT_RADIUS * angular_speed;
    motor_speed->speed3 = (sqrt(2) / 2.) * normal_speed -
                          (sqrt(2) / 2.) * tangential_speed +
                          ROBOT_RADIUS * angular_speed;
    motor_speed->speed4 = (sqrt(3) / 2.) * normal_speed +
                          (1. / 2.) * tangential_speed +
                          ROBOT_RADIUS * angular_speed;
}

void apply_motor_speed() {
    Motor_speed motor_speed;

    // TODO: Change this !
    compute_motor_speed(&motor_speed, 0.5, 0.5, 2.0);

    motor1.set_state(Commands_RUN);
    motor2.set_state(Commands_RUN);
    motor3.set_state(Commands_RUN);
    motor4.set_state(Commands_RUN);
    motor1.set_speed(motor_speed.speed1);
    motor2.set_speed(motor_speed.speed2);
    motor3.set_speed(motor_speed.speed3);
    motor4.set_speed(motor_speed.speed4);
}

void stop_motors() {
    motor1.set_state(Commands_STOP);
    motor2.set_state(Commands_STOP);
    motor3.set_state(Commands_STOP);
    motor4.set_state(Commands_STOP);
    motor1.set_speed(0.0);
    motor2.set_speed(0.0);
    motor3.set_speed(0.0);
    motor4.set_speed(0.0);
}

void print_communication_status() {
    printf("Motor1 TX errors: %ld\n", motor1.get_tx_error_count());
    printf("Motor1 RX errors: %ld\n", motor1.get_rx_error_count());
    printf("Motor2 TX errors: %ld\n", motor2.get_tx_error_count());
    printf("Motor2 RX errors: %ld\n", motor2.get_rx_error_count());
    printf("Motor3 TX errors: %ld\n", motor3.get_tx_error_count());
    printf("Motor3 RX errors: %ld\n", motor3.get_rx_error_count());
    printf("Motor4 TX errors: %ld\n", motor4.get_tx_error_count());
    printf("Motor4 RX errors: %ld\n", motor4.get_rx_error_count());
}

int main() {
    driver_spi.frequency(500000);

    // MotorManager m;
    // motor1.set_communication_period(10);
    // motor2.set_communication_period(10);
    // motor3.set_communication_period(10);
    // motor4.set_communication_period(10);

    // motor1.start_communication();
    // motor2.start_communication();
    // motor3.start_communication();
    // motor4.start_communication();

    // stop_motors();
    //  ThisThread::sleep_for(1s);

    while (true) {
        led = !led;
        // apply_motor_speed();
        // print_communication_status();

        ThisThread::sleep_for(BLINKING_RATE);
    }
}
