#ifndef _CONFIG_H
#define _CONFIG_H
    // wifi config
    #define APSSID "DEV_WIFI"
    #define APPSK  "1234567890"

    // slave address in byte
    #define MAIN_ECU            0x01 // relays controller + 1 digit led display + indicator leds + light sensor
    #define LEFT_TAIL           0x02 // adress of left tail light arduino
    #define RIGHT_TAIL          0x03 // adress of right tail light arduino

    // slave commands in byte
    #define SWITCH_ELEMENT      0x01 // on/off relay via wifi
    #define CHANGE_ANIMATION    0x02 // change animation - turn_signal or break via wifi
    #define UPDATE_SETTINGS     0x03 // update delays and initial mode of relays
    #define SHOW_MODE           0x04 // activate show mode in tail_setup via wifi

    // states
    #define OFF                 0x00 // aways off
    #define ON                  0x01 // aways on + delay
    #define AUTO                0x02 // light sensor ontrolled

    // elements in MAIN_ECU to controll
    #define DRL                 0x00 // relay 1 + led
    #define INTERIOR            0x01 // relay 2 + led
    #define AMP                 0x02 // relay 3 + led
    #define FREE                0x03 // relay 4 + led
    
    // elements in LEFT_TAIL and RIGHT_TAIL to controll (switch animations)
    #define TURN_SIGNAL         0x03 // pointer to switch turn signal animation in X tail light
    #define BREAK               0x04 // pointer to switch brake animation in X tail light

    // pin definitions
    // display pins

    // input pins (buttons/sensors)
    //!!! to edit pin numbers
    #define BTN_ONE             1 // toggle relay 1
    #define BTN_TWO             2 // toggle relay 2
    #define BTN_TREE            3 // toggle relay 3
    #define BTN_FOUR            4 // toggle relay 4
    #define BTN_SHOWMODE        5 // toggle show mode on/off


#endif