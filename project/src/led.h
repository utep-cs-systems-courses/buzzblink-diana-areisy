#ifndef led_included
#define led_included
#include <msp430.h>

#define LED_GREEN BIT0      // P1.0
#define LED_RED BIT6        // P1.6
#define LEDS (BIT0 | BIT6)

extern unsigned char led_changed;

void led_init();            //Initialize LEDs
void led_update();          //Update LEDs
void green_on(int on);      //Turn on/off green light
void red_on(int on);        //Turn on/off red lights
void led_off();

// These are boolean flags
extern unsigned char leds_changed, gree_led_state, red_led_state;

#endif // included
