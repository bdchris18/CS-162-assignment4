#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include "event.h"

class Room{
private:
    bool is_event_;
    bool has_player_;
    Event* event_;
public:
    Room();
    Room(const Room &old_dungeon);
    ~Room();
    bool get_is_event();
    void  set_is_event(bool is_event);
    bool get_has_player();
    void set_has_player(bool has_player);
    void set_event(Event* event);
    Event* get_event();
    void dungeon_setup(int rows, std::vector<std::vector<Room> > &dungeon);
    void wumpus_move(int rows, std::vector<std::vector<Room> > &dungeon);

    // void move_player(char c);
    // void shoot_arrow(char c);
};

#endif