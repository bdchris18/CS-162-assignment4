#ifndef EVENT_H
#define EVENT_H

class Event{
public:
    virtual void set_name(char name) = 0;
    virtual char get_name() const = 0;
    virtual void percept() = 0;
    virtual void encounter() = 0;
};

#endif