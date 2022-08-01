#include <msp430.h>
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "buzzer_notes.h"
#include "state_machines.h"

// SWITCH 1
void play_song_1()
{
  static char curr_note = 0;
  static int  ledBool =0;
  // All notes of song, 0s are for break in between notes
  int notes[6] = {G0,G0,A0,G0,C0 B0};
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
void play_song_2(){
  static char curr_note = 0;
  static int  ledBool =0;
  // All notes of song, 0s are for break in between notes
  int notes[40] = {}; 
  int n = 40;
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
