#include "timer/timer.hpp"

void Timer::update(const Joystick& joystick, Screen& screen) {
    // decrement timer
    if (_isRunning && millis() - _previousTime >= 1000) {
        if (--_sec < 0) {
            _sec = 59;
            if (--_min < 0) {
                _min = 0;
                _sec = 0;

                _leftFlashing = true;
                _rightFlashing = true;
                _isRunning = false;
            }
        }
    }

    // joystick click
    if (joystick.isButtonClicked()) {
        // reset
        if (!_isRunning && _leftFlashing && _rightFlashing) {
            _leftFlashing = false;
        }
            // start
        else if (!_isRunning) {
            _leftFlashing = false;
            _rightFlashing = false;
            _isRunning = true;
        }
    }

    // joystick move
    Direction direction { joystick.getDirection() };
    if (!_isRunning && !(_leftFlashing && _rightFlashing)) {
        if (direction == Direction::LEFT && _rightFlashing) {
            _rightFlashing = false;
            _leftFlashing = true;
        }
        else if (direction == Direction::RIGHT && _leftFlashing) {
            _leftFlashing = false;
            _rightFlashing = true;
        }
        else if (direction == Direction::UP && joystick.isEnabled()) {
            if (_rightFlashing && ++_sec >= 59) _sec = 0;
            if (_leftFlashing && ++_min >= 99) _min = 0;
        }
        else if (direction == Direction::DOWN && joystick.isEnabled()) {
            if (_rightFlashing && --_sec < 0) _sec = 59;
            if (_leftFlashing && --_min < 0) _min = 99;
        }
    }

    // display
    int left { -1 }, right { -1 };
    if (!_rightFlashing || direction != Direction::NONE || (_rightFlashing && millis() - _previousTime >= 500)) {
        right = _sec;
    }
    if (!_leftFlashing || direction != Direction::NONE || (_leftFlashing && millis() - _previousTime >= 500)) {
        left = _min;
    }

    screen.setPoint(millis() - _previousTime < 500 || !_isRunning);

    screen.display(left, right);

    // delay
    if (millis() - _previousTime >= 1000) _previousTime = millis();
}