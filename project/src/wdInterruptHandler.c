#include <msp430.h>
#include "state_machines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void __interrupt_vec(WDT_VECTOR) WDT() // 250 interrupts/sec
{
  static int count = 0;
  if(++count == 2509)
    {
      btn_one();
    }
}
