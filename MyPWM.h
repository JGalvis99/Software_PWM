/* Ruler 1         2         3         4         5         6         7        */

/********************************  MyPWM.h  *********************************/
/*                                                                            */
/*   Purpose: Header to operate Software PWM's                                */
/*                                                                            */
/******************************************************************************/

#ifndef MYPWM_H
#define MYPWM_H
#include "arduino.h"

/************************** Definition of Data Types **************************/

/* ------------------------------------PWM ---------------------------------- */

typedef enum {
HIGH_LEVEL, LOW_LEVEL} PWM_STATE_T;

typedef struct {
  long      duty_cycle;
  int       pin_out;
  long      period;
  long      previous_time;
  long      time_HI, time_LO;
  PWM_STATE_T state;
} ANALOG_WRITE_T;

/************************** Prototypes of Functions ***************************/

/* ---------------------------- Public Functions ---------------------------- */

void MyAnalogWriteSetup(ANALOG_WRITE_T *, int, int, int);
void MyAnalogWrite(ANALOG_WRITE_T *, int);

#endif /* MYPWM_H */
