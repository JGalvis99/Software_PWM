# Software_PWM
## For using the Software PWM, you must include the .h and .cpp to your folder project.
## 1. First in your main project, declare ANALOG_WRITE_T pin1, pin2, pin3 ... pinN;, as many pins as you have and want to use.
## 2. Second in your void setup, declare MyAnalogWriteSetup(pin1, 0 to 255 for duty cycle, pin out, frecuency [Hz]); you must declare this function for each pin in wich you want a software PWM.
## 3.Final in your void loop, declare MyAnalogWrite(&pin1, 0 to 255 for duty cicle); same as the second step you have to declare this line as many as PWM you are using.

However, you declare the duty cycle in the function MyAnalogWriteSetup, if you have a different duty cycle in MyAnalogWrite function the duty cycle that the system will use would be the one tou declared in MyAnalogWrite.
