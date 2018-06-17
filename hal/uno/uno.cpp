#include "hal.h"

#include <Arduino.h>

button_state hal_button_pressed()
{
    if (Serial.available())
    {
        char c = Serial.read();

        if (c == '\n')
        {
            return BTN_LONG_PRESS;
        }

        return BTN_SHORT_PRESS;
    }

    return BTN_IDLE;
}

// LED Hal

void hal_error_led(bool state)
{
    if (state)
    {
        Serial.println("ERROR");
    }
}

// Display Hal

void hal_disp_erase()
{
    Serial.println();
}

void hal_disp_show(unsigned int number)
{
    Serial.println(number, DEC);
}

void hal_setup()
{
    Serial.begin(9600);
}

void hal_loop()
{
}
