#include <msp430.h>
#include "state_machines.h"
#include "switches.h"

void __interrupt_vec(WDT_VECTOR) WDT() // 250 interrupts/sec
{
  static short count = 0;
  if (sw2_curr_stat) {
    if (++count > 50) {
      count = 0;
      btn_two();
    }
  }
  else if (sw3_curr_stat)
    btn_three();
}

