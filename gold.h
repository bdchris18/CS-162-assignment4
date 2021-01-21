#ifndef GOLD_H
#define GOLD_H
#include "event.h"

class Gold : public Event{
public:
    Gold();
    ~Gold();
    void set_name(char name);
    char get_name() const{return 'g';}
    void percept();
    void encounter();
};

#endif