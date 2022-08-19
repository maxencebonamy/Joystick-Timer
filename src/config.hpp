#pragma once

#include "Arduino.h"


namespace pin {
    const uint8_t joystickButton { 2 };
    const uint8_t joystickX { A1 };
    const uint8_t joystickY { A0 };

    const uint8_t screenDIO { 3 };
    const uint8_t screenCLK { 4 };
}


const int FPS { 60 };