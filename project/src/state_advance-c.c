#include <msp430.h>
#include "switches.h"
#include "state_machines.h"
#include "state_advance.h"

void state_advance(int switchSM)
{
  switch (switchSM){
    case 0:
      btn_one();
      break;
    case 1:
      btn_two();
      break;
    case 2:
      btn_three();
      break;
    case 3:
      btn_four();
      break;
  }
}
