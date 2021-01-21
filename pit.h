#ifndef PIT_H
#define PIT_H
#include "event.h"

class Pit : public Event{
public:
    Pit();
    ~Pit();
    void set_name(char name);
    char get_name() const{return 'p';}
    void percept();
    void encounter();
};

#endif