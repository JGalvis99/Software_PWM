# Software_PWM
## For using the Software PWM, you must include the .h and .cpp to your folder project.
### First in your main project, declare ANALOG_WRITE_T pin1, pin2, pin3 ... pinN;, as many pins as you have and want to use.
### Second in your void setup, declare MyAnalogWriteSetup(pin1, 0 to 255 for duty cycle, pin out, frecuency [Hz]); you must declare this function for each pin in wich you want a software PWM.
### Final in your void loop, declare MyAnalogWrite(&pin1, 0 to 255 for duty cicle); same as the second step you have to declare this line as many as PWM you are using.

## NOTE: If you declare the duty cycle in function MyAnalogWriteSetup, and you have a different duty cycle in MyAnalogWrite function the duty cycle that the system will use is the one you declared in MyAnalogWrite.
