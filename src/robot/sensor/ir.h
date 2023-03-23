#pragma once

#include <mbed.h>
#include <swo.h>

namespace ir {
    extern float value;
    void compute();
    bool present();
}  // namespace ir