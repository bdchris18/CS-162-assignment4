#ifndef PLAYER_H
#define PLAYER_H
#include "event.h"

class Entrance : public Event{
public:
    Entrance();
    ~Entrance();
    void set_name(char name);
    void percept();
    char get_name() const{return 'e';}
    void encounter();
};

#endif