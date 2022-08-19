#pragma once

#include "TM1637.h"
#include "config.hpp"


class Screen {

public:
    Screen();

    void display(int left, int right);

    void setPoint(bool value);

private:
    TM1637 _screen { pin::screenCLK, pin::screenDIO };

    bool _point { true };

};
