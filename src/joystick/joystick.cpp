#include "joystick/joystick.hpp"


void Joystick::update() {
    if (_isButtonClicked && _isButtonPressed) _isButtonClicked = false;

    if (_getButtonValue() && !_isButtonPressed) {
        _isButtonPressed = true;
        _isButtonClicked = true;
    }
    else if (!_getButtonValue() && _isButtonPressed) {
        _isButtonPressed = false;
    }

    _isEnabled = false;
    if (millis() - _previousTime >= _interval) {
        _isEnabled = true;
        _previousTime = millis();
    }
}


Direction Joystick::getDirection() const {
    if (_getX() > 1000) return Direction::LEFT;
    else if (_getX() < 22) return Direction::RIGHT;
    else if (_getY() > 1000) return Direction::UP;
    else if (_getY() < 22) return Direction::DOWN;
    else return Direction::NONE;
}

bool Joystick::isButtonPressed() const {
    return _isButtonPressed;
}

bool Joystick::isButtonReleased() const {
    return !_isButtonPressed;
}

bool Joystick::isButtonClicked() const {
    return _isButtonClicked;
}


int Joystick::_getX() {
    return analogRead(pin::joystickX);
}

int Joystick::_getY() {
    return analogRead(pin::joystickY);
}

int Joystick::_getButtonValue() {
    return digitalRead(pin::joystickButton);
}

bool Joystick::isEnabled() const {
    return _isEnabled;
}
