#include "Arduino.h"
#include "config.h"
#include "comunication.h"
#include "inputs.h"

inputs::inputs(){}

void inputs::SETUP(){
    pinMode(BTN_ONE,INPUT);
}

void inputs::READ_INPUT(){
    // read input and prepare command then send it to board
    byte command[3] = {SWITCH_ELEMENT,DRL,OFF};
    COMUNICATION.SEND_COMMAND(MAIN_ECU,command);
}
void inputs::READ_LIGHT(){
    // read light value and store it
}
inputs INPUTS = inputs();