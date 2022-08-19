#include "joystick/joystick.hpp"
#include "screen/screen.hpp"
#include "config.hpp"
#include "timer/timer.hpp"


Joystick joystick;
Screen screen;

Timer timer;

void setup() {
    Serial.begin(9600);
}

void loop() {
    joystick.update();

    timer.update(joystick, screen);

    delay(1000 / FPS);
}