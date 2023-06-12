#include <Arduino.h>
#include "initialise.h"
#include "server_class.h"
#include "comunication.h"
#include "inputs.h"

void setup() {
  INITIALISE.BEGIN();
  SERVER_CLASS.SETUP();
  //COMUNICATION.SETUP();
  INPUTS.SETUP();
}

void loop() {
  SERVER_CLASS.LISTEN();
  INPUTS.READ_INPUT();
  INPUTS.READ_LIGHT();
  delay(50);
}