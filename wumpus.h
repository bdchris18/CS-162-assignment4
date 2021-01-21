#ifndef WUMPUS_H
#define WUMPUS_H
#include "event.h"

class Wumpus : public Event{
public:
    Wumpus();
    ~Wumpus();
    void set_name(char name);
    char get_name() const{return 'w';}
    void percept();
    void encounter();
};

#endif