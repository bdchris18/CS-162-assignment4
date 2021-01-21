#ifndef GAME_H
#define GAME_H
#include "room.h"

class Game{
private:
    bool has_gold_;
    bool alive_;
    bool win_;
public:
    Game();
    ~Game();
    Game(const Game &old_game);
    bool get_has_gold();
    void set_has_gold(bool has_gold);
    bool get_alive();
    void set_alive(bool alive);
    bool get_win();
    void set_win(bool win);
    void create_dungeon(int rows, std::vector<std::vector<Room> > &dungeon); 
    void print_dungeon(int rows, std::vector<std::vector<Room> > &dungeon, bool debug);
    void check_near_player(int rows, std::vector<std::vector<Room> > &dungeon);
    void move_player(std::string c, int rows, std::vector<std::vector<Room> > &dungeon);
    void check_spot(int rows, std::vector<std::vector<Room> > &dungeon);
    void shoot_arrow(Room r1, std::string c, int rows, std::vector<std::vector<Room> > &dungeon, int &arrows);
    // bool wumpus_move(int rows, std::vector<std::vector<Room> > &dungeon);
};

#endif