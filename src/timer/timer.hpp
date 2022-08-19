#pragma once

#include "Arduino.h"
#include "joystick/joystick.hpp"
#include "screen/screen.hpp"


class Timer {

public:
    Timer() = default;

    void update(const Joystick& joystick, Screen& screen);

private:
    bool _leftFlashing { false }, _rightFlashing { true };

    bool _isRunning { false };
    int _min { 0 }, _sec { 0 };

    unsigned long _previousTime { millis() };

};
