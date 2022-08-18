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
  static int  ledBool =0;
  // All notes of song, 0s are for break in between notes
  int notes[6] = {G0,G0,A0,G0,C0 B3};
  int n = 6;

  if (curr_note < n){
      buzzer_set_period(notes[curr_note]);
      curr_note++;
      if(ledBool){
	swap_leds(ledBool);
	ledBool =0;
      }
      else{
	swap_leds(ledBool);
	ledBool =1;
      }
	
  }
  else {
    curr_note = 0;
  }
  
}

// switch 2
void btn_two(){
  static char curr_note = 0;
  static int  ledBool =0;
  // All notes of song, 0s are for break in between notes
  int notes[7] = {C4, A4, G7, G7, C4,A0, G7, G7}; 
  int n = 7 ;
  if (curr_note < n){
      buzzer_set_period(notes[curr_note]);
      curr_note++;
      if(ledBool){
	swap_leds(ledBool);
	ledBool =0;
      }
      else{
	swap_leds(ledBool);
	ledBool =1;
      }
	
  }
  else {
    curr_note = 0;
  }
}
void btn_three(){
  green_on ^= 1;
  led_changed = 1;
  led_update();
  buzzer_set_period(7500);
}

void btn_four(){
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
  buzzer_set_period(0);
}
