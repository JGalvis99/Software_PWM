#include "MyPWM.h"
ANALOG_WRITE_T led1,led2,led3;

void setup(){
MyAnalogWriteSetup(&led1, 127, 11,1);
MyAnalogWriteSetup(&led2, 127, 12,2);
MyAnalogWriteSetup(&led3, 127, 13,4);
}

void loop(){
MyAnalogWrite(&led1, 127);
MyAnalogWrite(&led2, 127);
MyAnalogWrite(&led3, 127);

}
