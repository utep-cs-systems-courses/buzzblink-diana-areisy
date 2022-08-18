#include <msp430.h>
#include <time.h>
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "stateMachines.h"
#include "state_advance.h"

void state_advance(switchSM)		/* alternate between toggling red & green */
{
  switch (switchSM){
    case 0:
      btn_one();
      break;
    case 1:
      btn_two();
      break;
    case 2:
      btn_tree();
      break;
    case 3:
      btn_four();
      break;
  }
}
