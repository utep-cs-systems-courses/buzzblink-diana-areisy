#ifndef switches_included
#define switches_included

#define SW1 BIT0   // Switch 1 is p2.0
#define SW2 BIT1   // Switch 2 is p2.1
#define SW3 BIT2   // Switch 3 is p2.2
#define SW4 BIT3   // Switch 4 is p2.3

#define SWITCHES (SW1 | SW2 | SW3 | SW4)  // All four switches on Port 2

void switch_init();
void switch_interrupt_handler();

extern char sw1_curr_stat;
extern char sw2_curr_stat;
extern char sw3_curr_stat;
extern char sw4_curr_stat;
#endif 
