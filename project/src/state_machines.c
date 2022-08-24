#include <msp430.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "buzzer_notes.h"
#include "state_machines.h"

// SWITCH 1
void btn_one()
{
  static char curr_note = 0;
  // All notes of song, 0s are for break in between notes
  int notes[14] = {C2,C2,F2,F2,C3,C3,F3,F3,A4,A4,F4,F4,0,0};
  int n = 14;

  P1OUT &= ~LEDS;
  if (curr_note < n)
    buzzer_set_period(notes[curr_note++]);
  else
    curr_note = 0; 
}

// switch 2
void btn_two(){
  static char i = 0;
  static int colors[13] = {LED_RED, LED_RED, LED_RED, ~LEDS, LED_GREEN, LED_GREEN, LED_GREEN, ~LEDS, LED_RED, LED_RED, LED_RED, ~LEDS, ~LEDS}; 
  static int n = 13;

  if (P1OUT & LEDS)
    P1OUT &= ~LEDS;
  else
    P1OUT |= colors[i++];

  if (i >= n) i = 0;
}

// Switch 3
int blinkCount = 0;
int secondCount = 0;
int blinkLimit = 0;

void btn_three()
{
  // handle blinking
  if (++blinkCount >= blinkLimit) { // on for 1 interrupt period
    blinkCount = 0;
    P1OUT |= LED_GREEN;
  } else		          // off for blinkLimit - 1 interrupt periods
    P1OUT &= ~LED_GREEN;

  // measure a second
  if (++secondCount >= 250) {  // once each second
    secondCount = 0;
    blinkLimit ++;	     // reduce duty cycle
    if (blinkLimit >= 8)     // but don't let duty cycle go below 1/7.
      blinkLimit = 0;
  }
}

void btn_four(){
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
  buzzer_set_period(0);
}

