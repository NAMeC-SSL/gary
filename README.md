# GARY: RoboCup SSL Robot and Base Station Firmware

This firmware is designed for custom RoboCup SSL robots and base stations using the ZEST_CORE_STM32L4A6RG mainboard created by CATIE.
The firmware is built using [PlatformIO](https://platformio.org/) with [Mbed OS](https://os.mbed.com/).

The firmware has two primary use cases:

- **Robot**: Controls the overall robot functions, including kicking, dribbling, and movement. The robots are also able to detect if they have the ball and identify themselves.
- **Base station**: Manages communication with the robots and our PC software.

## Hardware

- Mainboard: ZEST_CORE_STM32L4A6RG (STM32L4A6RG-based custom board by CATIE)
- Wireless Communication: nRF24L01+

## Getting Started

### Prerequisites

Install [PlatformIO](https://platformio.org/)
You can check "Disable PIO Home Startup" in VSCode settings.

### Documents

Datasheets and other documentation can be found in the `docs` folder.

### Build and Upload

To build and upload the firmware to the mainboard, use the following commands:

- For the robot:

> pio run -t upload -e robot

- For the base station

> pio run -t upload -e base_station

## Licensing

This project is licensed under the GNU General Public License v3.0 (GPL-3.0). See the [LICENSE-GPL-3.0](LICENSE-GPL-3.0) file for details.

The ZEST_CORE_STM32L4A6RG mainboard and PIO library are licensed under the Apache License, Version 2.0. See the [LICENSE-Apache-2.0](LICENSE-Apache-2.0) file for details.
