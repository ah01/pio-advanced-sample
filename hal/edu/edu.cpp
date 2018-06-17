#include "edu.h"

#include <Arduino.h>
#include <Bounce2.h>
#include <edushield.h>

static Bounce btn_bounce(BUTTON_PIN, 50);
static unsigned long press_time;

button_state hal_button_pressed()
{
    btn_bounce.update();

    if (btn_bounce.fallingEdge())
    {
        press_time = millis();
    }

    if (btn_bounce.risingEdge())
    {
        unsigned long d = millis() - press_time;

        return (d > 500) ? BTN_LONG_PRESS : BTN_SHORT_PRESS;
    }

    return BTN_IDLE;
}

// LED Hal

void hal_error_led(bool state)
{
    digitalWrite(ERROR_LED, state);
}

// Display Hal

void hal_disp_erase()
{
    Display.set4(0, 0, 0, 0);
}

void hal_disp_show(unsigned int number)
{
    Display.number(number);
}

void hal_setup()
{
    pinMode(ERROR_LED, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);

    // init values
    hal_error_led(false);
    hal_disp_erase();
}

void hal_loop()
{
}
