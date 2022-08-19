#pragma once

#include "config.hpp"


enum class Direction {
    LEFT, RIGHT, UP, DOWN, NONE
};


class Joystick {

public:
    void update();

    Direction getDirection() const;
    bool isButtonPressed() const;
    bool isButtonReleased() const;
    bool isButtonClicked() const;

    bool isEnabled() const;

private:
    static int _getX() ;
    static int _getY() ;
    static int _getButtonValue() ;

    bool _isButtonPressed { false };
    bool _isButtonClicked { false };

    bool _isEnabled { true };
    unsigned long _previousTime { millis() };
    int _interval { 200 };

};
