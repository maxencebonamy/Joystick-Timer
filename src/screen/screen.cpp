#include "screen/screen.hpp"


Screen::Screen() {
    _screen.init();
    _screen.set(BRIGHT_TYPICAL);
}

void Screen::display(int left, int right) {
    _screen.clearDisplay();
    _screen.point(_point);

    if (left != -1) {
        int8_t a { static_cast<int8_t>(left / 10) },
               b { static_cast<int8_t>(left - a * 10) };

        _screen.display(0, a);
        _screen.display(1, b);
    }

    if (right != -1) {
        int8_t a { static_cast<int8_t>(right / 10) },
               b { static_cast<int8_t>(right - a * 10) };

        _screen.display(2, a);
        _screen.display(3, b);
    }
}

void Screen::setPoint(bool value) {
    if (value != _point) {
        _point = value;
    }
}
