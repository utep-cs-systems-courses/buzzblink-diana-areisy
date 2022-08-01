#include <msp430.h>
#include "switches.h"

//Switches on P2

void __interrupt_vec(PORT2_VECTOR) PORT_2()
{
  if(P2IFG & SWITCHES) // did a button cause this interrupt
    {
      P2IFG &= ~SWITCHES; // clear pending sw interrupts
      switch_interrupt_handler(); // SIngle handler for all switches
    }
}

int sw1_press_state = 0;
int sw2_press_state = 0;
int sw3_press_state = 0;
int sw4_press_state = 0;

void __interrupt_vec(WDT_VECTOR) WDT() // 250 interrupts/sec
{
  static int count = 0;
  count++;

  if((count % 63) == 0 && sw1_press_state == 1)
    {
      led_update();
      play_song_1();
      count = 0;
    }
  else if((count % 31) == 0 && sw2_press_state == 1)
    {
      led_update();
      play_song_2();
      count = 0;
    }
  else if((count % 31) == 0 && sw3_press_state == 1)
    {
      led_update();
      count = 0;
    }
  else if((count % 125) == 0 && sw4_press_state == 1)
    {
      buzzer_set_period(0);
      count = 0;
    }
}
