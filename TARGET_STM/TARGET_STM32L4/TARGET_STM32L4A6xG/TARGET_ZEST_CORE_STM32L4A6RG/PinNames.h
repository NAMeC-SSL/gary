/* mbed Microcontroller Library
 *******************************************************************************
 * Copyright (c) 2016, STMicroelectronics
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */

/* MBED TARGET LIST: ZEST_CORE_STM32L4A6RG */

#ifndef MBED_PINNAMES_H
#define MBED_PINNAMES_H

#include "cmsis.h"
#include "PinNamesTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ALT0  = 0x100,
    ALT1  = 0x200,
    ALT2  = 0x300,
    ALT3  = 0x400
} ALTx;

typedef enum {
    PA_0  = 0x00,
    PA_0_ALT0 = PA_0 | ALT0,
    PA_1  = 0x01,
    PA_1_ALT0 = PA_1 | ALT0,
    PA_2  = 0x02,
    PA_2_ALT0 = PA_2 | ALT0,
    PA_3  = 0x03,
    PA_3_ALT0 = PA_3 | ALT0,
    PA_4  = 0x04,
    PA_4_ALT0 = PA_4 | ALT0,
    PA_5  = 0x05,
    PA_5_ALT0 = PA_5 | ALT0,
    PA_6  = 0x06,
    PA_6_ALT0 = PA_6 | ALT0,
    PA_7  = 0x07,
    PA_7_ALT0 = PA_7 | ALT0,
    PA_7_ALT1 = PA_7 | ALT1,
    PA_7_ALT2 = PA_7 | ALT2,
    PA_8  = 0x08,
    PA_9  = 0x09,
    PA_10 = 0x0A,
    PA_11 = 0x0B,
    PA_12 = 0x0C,
    PA_13 = 0x0D,
    PA_14 = 0x0E,
    PA_15 = 0x0F,
    PA_15_ALT0 = PA_15 | ALT0,
    PB_0  = 0x10,
    PB_0_ALT0 = PB_0 | ALT0,
    PB_0_ALT1 = PB_0 | ALT1,
    PB_1  = 0x11,
    PB_1_ALT0 = PB_1 | ALT0,
    PB_1_ALT1 = PB_1 | ALT1,
    PB_2  = 0x12,
    PB_3  = 0x13,
    PB_3_ALT0 = PB_3 | ALT0,
    PB_4  = 0x14,
    PB_4_ALT0 = PB_4 | ALT0,
    PB_5  = 0x15,
    PB_5_ALT0 = PB_5 | ALT0,
    PB_6  = 0x16,
    PB_6_ALT0 = PB_6 | ALT0,
    PB_7  = 0x17,
    PB_7_ALT0 = PB_7 | ALT0,
    PB_8  = 0x18,
    PB_8_ALT0 = PB_8 | ALT0,
    PB_9  = 0x19,
    PB_9_ALT0 = PB_9 | ALT0,
    PB_10 = 0x1A,
    PB_10_ALT0 = PB_10 | ALT0,
    PB_11 = 0x1B,
    PB_11_ALT0 = PB_11 | ALT0,
    PB_12 = 0x1C,
    PB_13 = 0x1D,
    PB_13_ALT0 = PB_13 | ALT0,
    PB_14 = 0x1E,
    PB_14_ALT0 = PB_14 | ALT0,
    PB_14_ALT1 = PB_14 | ALT1,
    PB_15 = 0x1F,
    PB_15_ALT0 = PB_15 | ALT0,
    PB_15_ALT1 = PB_15 | ALT1,
    PC_0  = 0x20,
    PC_0_ALT0 = PC_0 | ALT0,
    PC_0_ALT1 = PC_0 | ALT1,
    PC_1  = 0x21,
    PC_1_ALT0 = PC_1 | ALT0,
    PC_1_ALT1 = PC_1 | ALT1,
    PC_2  = 0x22,
    PC_2_ALT0 = PC_2 | ALT0,
    PC_2_ALT1 = PC_2 | ALT1,
    PC_3  = 0x23,
    PC_3_ALT0 = PC_3 | ALT0,
    PC_3_ALT1 = PC_3 | ALT1,
    PC_4  = 0x24,
    PC_4_ALT0 = PC_4 | ALT0,
    PC_5  = 0x25,
    PC_5_ALT0 = PC_5 | ALT0,
    PC_6  = 0x26,
    PC_6_ALT0 = PC_6 | ALT0,
    PC_7  = 0x27,
    PC_7_ALT0 = PC_7 | ALT0,
    PC_8  = 0x28,
    PC_8_ALT0 = PC_8 | ALT0,
    PC_9  = 0x29,
    PC_9_ALT0 = PC_9 | ALT0,
    PC_10 = 0x2A,
    PC_10_ALT0 = PC_10 | ALT0,
    PC_11 = 0x2B,
    PC_11_ALT0 = PC_11 | ALT0,
    PC_12 = 0x2C,
    PC_13 = 0x2D,
    PC_14 = 0x2E,
    PC_15 = 0x2F,
    PD_2  = 0x32,
    PH_0  = 0x70,
    PH_1  = 0x71,
    PH_3  = 0x73,

    /**** ADC internal channels ****/
    
    ADC_TEMP = 0xF0,  // Internal pin virtual value
    ADC_VREF = 0xF1,  // Internal pin virtual value
    ADC_VBAT = 0xF2,  // Internal pin virtual value

    // STDIO for console print
#ifdef MBED_CONF_TARGET_STDIO_UART_TX
    CONSOLE_TX = MBED_CONF_TARGET_STDIO_UART_TX,
#else
    CONSOLE_TX = PC_4,
#endif
#ifdef MBED_CONF_TARGET_STDIO_UART_RX
    CONSOLE_RX = MBED_CONF_TARGET_STDIO_UART_RX,
#else
    CONSOLE_RX = PC_5,
#endif

	// UART Fix to be compatible with mbed version prior to 6.10
    STDIO_UART_TX = CONSOLE_TX,
    STDIO_UART_RX = CONSOLE_RX,
    SERIAL_TX   = STDIO_UART_TX,
    SERIAL_RX   = STDIO_UART_RX,
    USBTX       = STDIO_UART_TX,
    USBRX       = STDIO_UART_RX,

    /**** Zest connector signal namings (J1) ****/
    CAN1_RX     = PB_12,        // CAN2_RX
    CAN1_TX     = PB_13,        // CAN2_TX
    I2C1_SCL    = PC_0,         // I2C3_SCL
    I2C1_SDA    = PC_1,         // I2C3_SDA
    UART1_RX    = PA_3,         // USART2_RX
    UART1_TX    = PA_2,         // USART2_TX
    SPI1_MOSI   = PB_15,        // SPI2_MOSI
    SPI1_MISO   = PB_14,        // SPI2_MISO
    SPI1_SCK    = PB_10,        // SPI2_SCK
    SPI1_CS     = PB_2,         // GPIO_28
    PWM1_OUT    = PA_10,        // TIM1_CH3
    PWM2_OUT    = PA_9,         // TIM1_CH2
    PWM3_OUT    = PB_0_ALT0,    // TIM3_CH3
    ICAPT1      = PB_1_ALT0,    // TIM3_CH4
    WKUP        = PC_13,        // WKUP2
    ADC_IN1     = PC_2,         // ADC123_IN3
    ADC_IN2     = PC_3,         // ADC123_IN4
    ADC_IN3     = PA_0,         // ADC12_IN5   
    ADC_IN4     = PA_1,         // ADC12_IN6
    DAC_OUT1    = PA_5,         // DAC_OUT2
    DIO1        = PB_5,         // GPIO_57
    DIO2        = PB_4,         // GPIO_56
    DIO3        = PD_2,         // GPIO_54
    DIO4        = PC_12,        // GPIO_53
    DIO5        = PA_8,         // GPIO_41 (MCO)
    DIO6        = PC_10,        // GPIO_51
    DIO7        = PA_6,         // GPIO_22
    DIO8        = PA_7,         // GPIO_23
    DIO9        = PA_4,         // GPIO_20
    DIO10       = PH_1,         // GPIO_06
    DIO11       = PH_0,         // GPIO_05
    DIO12       = PB_7,         // GPIO_59
    DIO13       = PC_6,         // GPIO_37
    DIO14       = PC_7,         // GPIO_38
    DIO15       = PC_8,         // GPIO_39
    DIO16       = PC_9,         // GPIO_40
    DIO17       = PC_11,        // GPIO_52
    DIO18       = PB_6,         // GPIO_58
    DIO19       = PB_8,         // GPIO_61
    DIO20       = PB_9,         // GPIO_62

    /**** USB FS pins ****/
    USB_OTG_FS_DM = PA_11,
    USB_OTG_FS_DP = PA_12,

    /**** OSCILLATOR pins ****/
    RCC_OSC32_IN = PC_14,
    RCC_OSC32_OUT = PC_15,

    /**** DEBUG pins ****/
    SYS_JTCK_SWCLK = PA_14,
    SYS_JTDI = PA_15,
    SYS_JTDO_SWO = PB_3,
    SYS_JTMS_SWDIO = PA_13,
    SYS_WKUP2 = WKUP,

    // Not connected
    NC = (int)0xFFFFFFFF
} PinName;

// Standardized LED and button names
#define LED1    PB_11
#define BUTTON1 PH_3

#ifdef __cplusplus
}
#endif

#endif
