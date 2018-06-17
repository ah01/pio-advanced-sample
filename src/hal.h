#ifndef _hal_h_
#define _hal_h_

// Button HAL

typedef enum {
    BTN_IDLE = 0, 
    BTN_SHORT_PRESS, 
    BTN_LONG_PRESS
} button_state;

button_state hal_button_pressed();

// LED Hal

void hal_error_led(bool state);

// Display Hal

void hal_disp_erase();
void hal_disp_show(unsigned int number);

// Main Hal functions

void hal_setup();
void hal_loop();

#endif
