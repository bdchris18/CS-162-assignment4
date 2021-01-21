#ifndef BATS_H
#define BATS_H
#include "event.h"

class Bats : public Event{
public:
    Bats();
    ~Bats();
    void set_name(char name);
    char get_name() const{return 'b';}
    void percept();
    void encounter();
};

#endif