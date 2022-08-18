#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char switch_state_changed;
short switchSM;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void switch_init()		/* setup switch */
{
  P2REN |= SWITCHES;	/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;	/* pull-ups for switches */
  P2DIR &= ~SWITCHES;	/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  //Chech each button
  char sw1_curr_stat = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  char sw2_curr_stat = (p2val & SW2) ? 0 : 1; /* 0 when SW2 is up */
  char sw3_curr_stat = (p2val & SW3) ? 0 : 1; /* 0 when SW3 is up */
  char sw4_curr_stat = (p2val & SW4) ? 0 : 1; /* 0 when SW4 is up */
 

  if (sw1_curr_stat){switchSM = 0;}
  else if(sw2_curr_stat){switchSM = 1;}
  else if(sw3_curr_stat){switchSM = 2;}
  else if(sw4_curr_stat){switchSM = 3;} 
  switch_state_changed = 1;
  state_advance(switchSM);
  
}
