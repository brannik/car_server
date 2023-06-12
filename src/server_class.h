#ifndef server_class_h
#define server_class_h

class server_class{
    public:
    server_class();
    void SETUP();
    void LISTEN();
    void REPLY();
};

extern server_class SERVER_CLASS;
#endif