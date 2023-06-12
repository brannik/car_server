#include "Arduino.h"
#include "config.h"
#include "server_class.h"
#include "comunication.h"

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>


const char* ssid = APSSID;
const char* password = APPSK;

server_class::server_class(){}

WebServer server(80);


// handlers

void handleDefault(){
    server.send(200, "text/html", "<h1>If you see this message, it's likely that your computer is infected with a virus  :) :) :)</h1>");
    // process requests here 
    // !!!!!!!!!!!! test /*action, target_element,value*/
}

void handle_welcome(){
    // send message to new client

}

void handle_switches(){
    // process switched modules via wifi
    // $data = server.arg("$arg_name_send_from_client")
    // send data to slave
    byte command[3] = {SWITCH_ELEMENT,DRL,OFF};
    COMUNICATION.SEND_COMMAND(MAIN_ECU,command);
}

void handle_save_options(){
    // save settings to EEPROM

}

void handle_show_mode(){
    // send commant to showmode on/off
    COMUNICATION.SHOW_MODE_COMMAND(LEFT_TAIL,SHOW_MODE);
    COMUNICATION.SHOW_MODE_COMMAND(RIGHT_TAIL,SHOW_MODE);
}

void handle_return_settings(){
    // send all settings to android device over wifi
    server.send(200, "text/html", "JSON format settings");
}


// main functions
void server_class::SETUP(){
    Serial.begin(9600);
    WiFi.softAP(ssid, password);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);


    server.on("/welcome",handle_welcome);
    server.on("/switch",handle_switches);
    server.on("/save_options",handle_save_options);
    server.on("/swhomode",handle_show_mode);
    server.on("/get_settings",handle_return_settings);
    server.onNotFound(handleDefault);
    server.begin();
}

void server_class::LISTEN(){
    server.handleClient();
    delay(100);
}

server_class SERVER_CLASS = server_class();