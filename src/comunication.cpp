#include "Arduino.h"
#include "comunication.h"
#include "config.h"
#include "Wire.h"


comunication::comunication(){}

void comunication::SETUP(){
    // configure slaves
}

void comunication::SEND_COMMAND(int slaveAddr,byte command[3] /*action, target_element,value*/){
    // send data to slaves
    Wire.beginTransmission(slaveAddr);
    Wire.write(command[0]);
    Wire.write(command[1]);
    Wire.write(command[2]);
    Wire.endTransmission();
}

void comunication::SHOW_MODE_COMMAND(byte slaveAddr,byte element){
    // send command to run show mode or not
    Wire.beginTransmission(slaveAddr);
    Wire.write(element);
    Wire.endTransmission();
}

comunication COMUNICATION = comunication();