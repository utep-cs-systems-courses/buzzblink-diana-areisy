#include <msp430.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "buzzer_notes.h"
#include "state_machines.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;
  led_changed = 1;
  led_update();
}

void led_update()
{
  if (led_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on];
    P1OUT &= (0xff^LEDS) | ledFlags;
    P1OUT |= ledFlags;
    led_change = 0;
    
}

void red_on(int on)
{
  if(on)
    {
      P1OUT |= LED_RED;
      red_on = 1;
    }
  else
    P1OUT &= ~LED_RED;
    red_on = 0;
}

void green_on(int on)
{
  if(on)
    {
      P1OUT |= LED_GREEN;
      green_on = 1;
    } else {
      P1OUT &= ~LED_GREEN;
      green_on = 0;
  }
}
 
void leds_on(int on)
  {
    if(on)
      {
	P1OUT |= LEDS;
      }else
      P1OUT &= ~LEDS;
  }
  
void leds_off()
{
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
  
}
      
 void swap_leds(int on)
 {
   switch(on)
     {
     case 0:
       red_on(1);
       green_on(0);
       break;
     case 1:
       red_on(0);
       green_on(1);
       break;
     default:
       leds_on(0);
       break;
     }
 }
