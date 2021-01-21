
/*********************************************************************
** Program Filename: game.cpp
** Author: Brandon Christensen
** Date: 5/25/2020
** Description: Functions related to the game overall
** Input: varying per function
** Output: varying per function
*********************************************************************/
#include <vector>
#include <iostream>
#include <cstdlib>
#include "game.h"
#include "room.h"

/*********************************************************************
** Function: Game
** Description: default constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: game class created
*********************************************************************/ 
Game::Game(){
    has_gold_ = false;
    alive_ = true;
    win_ = false;
}

/*********************************************************************
** Function: ~Game
** Description: destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Game class deleted
*********************************************************************/ 
Game::~Game(){

}

/*********************************************************************
** Functions: getters and setters
** Description: get and set private variables
** Parameters: setters have their respective variables
** Pre-Conditions: unchanged value for setters
** Post-Conditions: returns for getters and value is set for setters
*********************************************************************/ 
bool Game::get_has_gold(){
    return has_gold_;
}

void Game::set_has_gold(bool has_gold){
    has_gold_ = has_gold;
}

bool Game::get_alive(){
    return alive_;
}

void Game::set_alive(bool alive){
    alive_ = alive;
}

bool Game::get_win(){
    return win_;
}

void Game::set_win(bool win){
    win_ = win;
}

/*********************************************************************
** Function: Game
** Description: copy constructor
** Parameters: reference to an old Game
** Pre-Conditions: empty Game class
** Post-Conditions: copied Game class
*********************************************************************/ 
Game::Game(const Game &old_game){
    has_gold_ = old_game.has_gold_;
    alive_ = old_game.alive_;
    win_ = old_game.win_;
}

/*********************************************************************
** Function: create_dungeon
** Description: creates the vector
** Parameters: an int rows, and a reference to the vector
** Pre-Conditions: empty vector
** Post-Conditions: 2d vector
*********************************************************************/ 
void Game::create_dungeon(int rows, std::vector<std::vector<Room> > &dungeon){
    for (int i = 0; i < rows; ++i){
        std::vector<Room> rooms;
        for (int n = 0; n < rows; ++n){ 
            Room r;     
            rooms.push_back(r);
        }
        dungeon.push_back(rooms);
    }
}

/*********************************************************************
** Function: print_dungeon
** Description: prints the vector
** Parameters: an int rows, a reference to the vector, and a boolean 
** Pre-Conditions: nothing printed
** Post-Conditions: vector displayed
*********************************************************************/ 
/* Justification */
/* useless to make this multiple functions*/
/*               */
void Game::print_dungeon(int rows, std::vector<std::vector<Room> > &dungeon, bool debug){
    for (int i = 0; i < rows; ++i){
        for (int n = 0; n < rows; ++n){
            std::cout << "--";
        }
        
        std::cout << std::endl;
        if(debug == true){
            for (int n = 0; n < rows; ++n){
                if(dungeon[i][n].get_has_player() == true){
                    std::cout << "|*";
                }
                else{
                    std::cout << "|" << (dungeon[i][n].get_is_event() ? dungeon[i][n].get_event()->get_name() : '.');
                }
            }

        }
        else{
            for (int n = 0; n < rows; ++n){
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
        
    }
}

/*********************************************************************
** Function: check_near_player
** Description: checks what events are near the player
** Parameters: int rows and a reference to the vector
** Pre-Conditions: unknown events nearby
** Post-Conditions: prints respective statements
*********************************************************************/
/* Justification */
/* just barely over 15 lines*/
/*               */ 
void Game::check_near_player(int rows,std::vector<std::vector<Room> > &dungeon){
    for(int i = 0; i < rows; ++i){
        for(int n = 0; n < rows; ++n){
            if(!dungeon[i][n].get_has_player()) continue;
            if(i-1 >= 0 && dungeon[i-1][n].get_event() != NULL){
                dungeon[i-1][n].get_event()->percept();
            }
            if(i+1 <= rows-1 && dungeon[i+1][n].get_event() != NULL){
                dungeon[i+1][n].get_event()->percept();
            }
            if(n-1 >= 0 && dungeon[i][n-1].get_event() != NULL){
                dungeon[i][n-1].get_event()->percept();
            }
            if(n+1 <= rows-1 && dungeon[i][n+1].get_event() != NULL){
                dungeon[i][n+1].get_event()->percept();
            }
        }
    }
}

/*********************************************************************
** Function: move_player
** Description: moves the player to desired location
** Parameters: string of direction, an int number of rows, and a reference to the vector
** Pre-Conditions: player unmoved
** Post-Conditions: player moved
*********************************************************************/ 
/* Justification */
/* just barely over 15 lines*/
/*               */
void Game::move_player(std::string c, int rows, std::vector<std::vector<Room> > &dungeon){
    for(int i = 0; i < rows; ++i){  
        for(int n = 0; n < rows; ++n){      
            if(c == "w"){
                if(dungeon[i][n].get_has_player() && i-1 >= 0){
                    dungeon[i-1][n].set_has_player(true);
                    dungeon[i][n].set_has_player(false);
                }
            }
            else if(c == "a"){
                if(dungeon[i][n].get_has_player() && n-1 >= 0){
                    dungeon[i][n-1].set_has_player(true);
                    dungeon[i][n].set_has_player(false);
                }
            }
            else if(c == "s"){
                if(dungeon[i][n].get_has_player() && i+1 < rows){
                    dungeon[i+1][n].set_has_player(true);
                    dungeon[i][n].set_has_player(false);
                    return;
                }
            }
            else if(c == "d"){
                if(dungeon[i][n].get_has_player() && n+1 < rows){
                    dungeon[i][n+1].set_has_player(true);
                    dungeon[i][n].set_has_player(false);
                    return;
                }
            }
        }
    }
}

/*********************************************************************
** Function: check_spot
** Description: activates event based on what event the room has
** Parameters: an int for rows and a reference of the vector
** Pre-Conditions: unknown event at spot moved to
** Post-Conditions: user affected by an event otherwise nothing if NULL
*********************************************************************/ 
/* Justification */
/* pointless to make 5 functions that are 1 line long*/
/*               */
void Game::check_spot(int rows, std::vector<std::vector<Room> > &dungeon){
    for(int i = 0; i < rows; ++i){
        for(int n = 0; n < rows; ++n){
            if(dungeon[i][n].get_has_player()){
                if(dungeon[i][n].get_event() == NULL){
                    return;
                }
                else{
                    dungeon[i][n].get_event()->encounter();
                    if(dungeon[i][n].get_event()->get_name() == 'w'){
                        set_alive(false);
                    }
                    else if(dungeon[i][n].get_event()->get_name() == 'g'){
                        set_has_gold(true);
                    }
                    else if(dungeon[i][n].get_event()->get_name() == 'p'){
                        set_alive(false);
                    }
                    else if(dungeon[i][n].get_event()->get_name() == 'b'){
                        srand(time(NULL));
                        int rand_row = rand()%rows;
                        int rand_col = rand()%rows;
                        dungeon[rand_row][rand_col].set_has_player(true);
                        dungeon[i][n].set_has_player(false);
                    }
                    else if(dungeon[i][n].get_event()->get_name() == 'e' && has_gold_ == true){
                        std::cout << "You win!" << std::endl;
                        set_win(true);
                    }
                }
            }
        }
    }
}

/*********************************************************************
** Function: shoot arrow
** Description: shoots an arrow in direction of user input
** Parameters: Room class, a string with the direction, and int for rows and a reference of the vector
** Pre-Conditions: a direction to shoot
** Post-Conditions: wumpus will be dead or moved
*********************************************************************/ 
/* Justification */
/* If I made four seperate functions they would all have been */
/* longer than 15 lines anyway */
/*               */
void Game::shoot_arrow(Room r1, std::string c, int rows, std::vector<std::vector<Room> > &dungeon, int &arrows){
    for(int i = 0; i < rows; ++i){  
        for(int n = 0; n < rows; ++n){      
            if(c == "w"){
                if(dungeon[i][n].get_has_player()){
                    for(int a = 1; a < 4; ++a){
                        if(i-a < 0){
                            std::cout << "Your arrow hit a wall" << std::endl;
                            r1.wumpus_move(rows, dungeon);
                            arrows--;
                            return;
                        }
                        else if(dungeon[i-a][n].get_event() == NULL){
                            continue;
                        }
                        else if(dungeon[i-a][n].get_event()->get_name() == 'w'){
                            std::cout << "You killed the wumpus!" << std::endl;
                            Event* event_ = NULL;
                            dungeon[i-a][n].set_event(event_);
                            dungeon[i-a][n].set_is_event(false);
                            arrows--;
                            return;
                        }
                    }
                }
            }
            else if(c == "a"){
                if(dungeon[i][n].get_has_player()){
                    for(int a = 1; a < 4; ++a){
                        if(n-a < 0){
                            std::cout << "Your arrow hit a wall" << std::endl;
                            r1.wumpus_move(rows, dungeon);
                            arrows--;
                            return;
                        }
                        else if(dungeon[i][n-a].get_event() == NULL){
                            continue;
                        }
                        else if(dungeon[i][n-a].get_event()->get_name() == 'w'){
                            std::cout << "You killed the wumpus!" << std::endl;
                            Event* event_ = NULL;
                            dungeon[i][n-a].set_event(event_);
                            dungeon[i][n-a].set_is_event(false);
                            arrows--;
                            return;
                        }
                    }
                }
            }
            else if(c == "s"){
                if(dungeon[i][n].get_has_player()){
                    for(int a = 1; a < 4; ++a){
                        if(i+a > rows-1){
                            std::cout << "Your arrow hit a wall" << std::endl;
                            r1.wumpus_move(rows, dungeon);
                            arrows--;
                            return;
                        }
                        else if(dungeon[i+a][n].get_event() == NULL){
                            continue;
                        }
                        else if(dungeon[i+a][n].get_event()->get_name() == 'w'){
                            std::cout << "You killed the wumpus!" << std::endl;
                            Event* event_ = NULL;
                            dungeon[i+a][n].set_event(event_);
                            dungeon[i+a][n].set_is_event(false);
                            arrows--;
                            return;
                        }
                    }
                    return;
                }
            }
            else if(c == "d"){
                if(dungeon[i][n].get_has_player()){
                    for(int a = 1; a < 4; ++a){
                        if(n+a > rows-1){
                            std::cout << "Your arrow hit a wall" << std::endl;
                            r1.wumpus_move(rows, dungeon);
                            arrows--;
                            return;
                        }
                        else if(dungeon[i][n+a].get_event() == NULL){
                            continue;
                        }
                        else if(dungeon[i][n+a].get_event()->get_name() == 'w'){
                            std::cout << "You killed the wumpus!" << std::endl;
                            Event* event_ = NULL;
                            dungeon[i][n+a].set_event(event_);
                            dungeon[i][n+a].set_is_event(false);
                            arrows--;
                            return;
                        }
                        
                    }
                    return;
                }
            }
        }
    }
}