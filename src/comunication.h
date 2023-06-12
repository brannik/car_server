#ifndef comunication_h
#define comunication_h

class comunication{
    public:
    comunication();
    void SETUP();
    void SEND_COMMAND(int,byte[3] /*action, target_element,value*/);
    void SHOW_MODE_COMMAND(byte,byte);
};

extern comunication COMUNICATION;
#endif