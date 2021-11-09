/* Ruler 1         2         3         4         5         6         7        */

/********************************  MyPWM.cpp  *********************************/
/*                                                                            */
/*   Purpose: Module to make software PWM's                                   */
/*                                                                            */
/*   Origin:  Module tested and documented by D. Castro, J. Galvis,           */
/*            G. Segrera and D. Velásquez, since Oct 7, 2021.                 */
/*                                                                            */
/*   Notes:   None                                                            */
/*                                                                            */
/*   DATE         RESPONSIBLE  COMMENT                                        */
/*   -----------------------------------------------------------------------  */
/*   Oct 25/2019  J. Galvis                  Library implementation           */
/*   Oct 18/2019  Group                      Hardware Test                    */
/*   Oct 14/2017  G. Segrera                 Final implentation               */
/*   Oct 11/2021  J. Galvis & G. Segrera     Code changes                     */
/*   Oct 10/2021  G. Segrera                 Software test & code changes     */
/*   Oct 07/2021  D.Castro & D. Velásquez    Initial changes                  */
/*                                                                            */
/******************************************************************************/
/********************************** Headers ***********************************/

/* ------------------------ Inclusion of Std Headers ------------------------ */



/* ----------------------- Inclusion of Other Headers ----------------------- */

#include "MyPWM.h"
#include "arduino.h"

/*****************************  Public Functions  *****************************/


/*FN****************************************************************************
*
*   void MyAnalogWriteSetup(ANALOG_WRITE_T *fsm, int value, int pin, int frequency);
*
*   Purpose:  Set the variables of the intances for the PWM's
*
*   Note:            
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Oct 07/2021  J.C.Giraldo                Initial implementation
*   Oct 07/2021  D.Castro & D. Velásquez    Initial changes
*   Oct 14/2017  G. Segrera                 Final implentation
*   
*
*******************************************************************************/

void MyAnalogWriteSetup(ANALOG_WRITE_T *fsm, int value, int pin, int frequency){
    fsm->duty_cycle     = value;
    fsm->pin_out        = pin;
    fsm->period         = 1000000/frequency;
    fsm->previous_time  = micros();
    fsm->time_HI        = (value*fsm->period)/255;
    fsm->time_LO        = fsm->period - fsm->time_HI;
    fsm->state          = HIGH_LEVEL;
    pinMode(pin,OUTPUT);
    digitalWrite(pin,HIGH);
} /* MyAnalogWriteSetup */

/*FN****************************************************************************
*
*   void MyAnalogWrite(ANALOG_WRITE_T *fsm, int value);
*
*   Purpose:  Creates the PWM signal according the configuration setted on MyAnalogWriteSetup
*
*   Note:            
*
*   Register of Revisions (Debugging Process):
*
*   DATE         RESPONSIBLE  COMMENT
*   ------------------------------------------------------------------------
*   Oct 07/2021  J.C.Giraldo                Initial implementation
*   Oct 07/2021  D.Castro & D. Velásquez    Initial changes
*   Oct 10/2021  G. Segrera                 Software test & code changes
*   Oct 11/2021  J. Galvis & G. Segrera     Code changes  
*   Oct 14/2017  G. Segrera                 Final implentation
*
*******************************************************************************/

void MyAnalogWrite(ANALOG_WRITE_T *fsm, int value){
    switch(fsm->state){
        case HIGH_LEVEL:
            if(micros()-fsm->previous_time >= fsm->time_HI){
                digitalWrite(fsm->pin_out,LOW);
                fsm->previous_time  = micros();
                fsm->state          = LOW_LEVEL;
            }
        break;

        case LOW_LEVEL:
            if(micros() - fsm->previous_time >= fsm->time_LO){
                digitalWrite(fsm->pin_out,HIGH);
                fsm->previous_time = micros();
                if(value != fsm->duty_cycle){
                    fsm->time_HI        = (value*fsm->period)/255;
                    fsm->time_LO        = fsm->period - fsm->time_HI;
                    fsm->duty_cycle     = value;
                }
                fsm->state = HIGH_LEVEL;
            }
        break;
    }
} /* MyAnalogWrite */
