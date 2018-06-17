#include <Arduino.h>
#include <Wire.h>

#include "hal.h"
#include "core.h"

void setup() 
{
    hal_setup();

    hal_disp_show(core_get_counter());
}

void loop()
{
    hal_loop();

    auto btn = hal_button_pressed();

    if (btn == BTN_SHORT_PRESS) 
    {
        auto result = core_increment();

        if (result == false) {
            hal_error_led(true);
        }

        hal_disp_show(core_get_counter());
    }
    else if (btn == BTN_LONG_PRESS)
    {
        core_reset();
        hal_error_led(false);
        hal_disp_show(core_get_counter());
    }
}
