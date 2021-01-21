/*********************************************************************
** Program Filename: room.cpp
** Author: Brandon Christensen
** Date: 5/25/2020
** Description: Functions related to the rooms in the dungeon
** Input: varying per function
** Output: varying per function
*********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <ncurses.h>
#include "room.h"
#include "event.h"
#include "player.h"
#include "wumpus.h"
#include "gold.h"
#include "bats.h"
#include "pit.h"

/*********************************************************************
** Function: Room
** Description: default constructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Room class created
*********************************************************************/ 
Room::Room(){
    is_event_ = false;
    has_player_ = false;
    event_ = NULL;
}

/*********************************************************************
** Functions: getters and setters
** Description: get and set private variables
** Parameters: setters have their respective variables
** Pre-Conditions: unchanged value for setters
** Post-Conditions: returns for getters and value is set for setters
*********************************************************************/ 
bool Room::get_is_event(){
    return this->is_event_;
}

void Room::set_is_event(bool is_event){
    this->is_event_ = is_event;
}

bool Room::get_has_player(){
    return this->has_player_;
}

void Room::set_has_player(bool has_player){
    this->has_player_ = has_player;
}

void Room::set_event(Event* event){
    this->event_ = event;
}

Event* Room::get_event(){
    return this->event_;
}

Room::Room(const Room &old_dungeon){
    event_ = old_dungeon.event_;
    is_event_ = old_dungeon.is_event_;
    has_player_ = old_dungeon.has_player_;
}

/*********************************************************************
** Function: ~Room
** Description: destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: Room class deleted
*********************************************************************/ 
Room::~Room(){
    delete event_;
}

/*********************************************************************
** Function: dungeon_setup
** Description: fills dungeon woth events
** Parameters: an int rows and a reference to the vector
** Pre-Conditions: un filled vector
** Post-Conditions: events placed in random spots
*********************************************************************/ 
/* Justification */
/* lots of variable management I didn't want to deal with*/
/*               */
void Room::dungeon_setup(int rows, std::vector<std::vector<Room> > &dungeon){
    srand(time(NULL));
    bool valid = false;
    for(int i = 0; i < 7; ++i){
        while(!valid){
            int rand_row = rand()%rows;
            int rand_column = rand()%rows;
            if(i == 0){
                if(dungeon[rand_row][rand_column].get_event() == NULL){
                    event_ = new Wumpus;
                    dungeon[rand_row][rand_column].set_is_event(true);
                    dungeon[rand_row][rand_column].set_event(event_);
                    valid = true;
                }
            }
            else if(i == 1 || i == 2){
                if(dungeon[rand_row][rand_column].get_event() == NULL){
                    event_ = new Pit;
                    dungeon[rand_row][rand_column].set_is_event(true);
                    dungeon[rand_row][rand_column].set_event(event_);
                    valid = true;
                }
            }
            else if(i == 3 || i == 4){
                if(dungeon[rand_row][rand_column].get_event() == NULL){
                    event_ = new Bats;
                    dungeon[rand_row][rand_column].set_is_event(true);
                    dungeon[rand_row][rand_column].set_event(event_);
                    valid = true;
                }
            }
            else if(i == 5){
                if(dungeon[rand_row][rand_column].get_event() == NULL){
                    event_ = new Gold;
                    dungeon[rand_row][rand_column].set_is_event(true);
                    dungeon[rand_row][rand_column].set_event(event_);
                    valid = true;
                }
            }
            else{
                if(dungeon[rand_row][rand_column].get_event() == NULL){
                    event_ = new Entrance;
                    dungeon[rand_row][rand_column].set_has_player(true);
                    dungeon[rand_row][rand_column].set_is_event(true);
                    dungeon[rand_row][rand_column].set_event(event_);
                    valid = true;
                }
            }
        }
        valid = false;
    }
}

/*********************************************************************
** Function: wumpus_move
** Description: moves wumpus to a new cell
** Parameters: an int rows, and a reference to the vector
** Pre-Conditions: unmoved wumpus
** Post-Conditions: 75% chance wumpus is moved
*********************************************************************/ 
/* Justification */
/* Useless to have multiple functions here aas they would be really short*/
/*               */
void Room::wumpus_move(int rows, std::vector<std::vector<Room> > &dungeon){
    int chance = rand()%4+1;
    if(chance > 1){
        for(int i = 0; i < rows; ++i){
            for(int n = 0; n < rows; ++n){
                if(dungeon[i][n].get_event() == NULL){
                    continue;
                }
                if(dungeon[i][n].get_event()->get_name() == 'w'){
                    std::cout << "no seg" << std::endl;
                    dungeon[i][n].get_event()->set_name('.');
                    dungeon[i][n].set_event(NULL);
                    dungeon[i][n].set_is_event(false);
                }
            }
        }
        for(int i = 0; i < rows; ++i){
            for(int n = 0; n < rows; ++n){
                while(1){
                    int rand_row = rand()%rows;
                    int rand_col = rand()%rows;
                    if(dungeon[rand_row][rand_col].get_event() == NULL){
                        event_ = new Wumpus;
                        dungeon[rand_row][rand_col].set_event(event_);
                        dungeon[rand_row][rand_col].set_is_event(true);
                        std::cout << "The wumpus moved rooms" << std::endl;
                        return;
                    }
                }
            }
        }
    }
    else{
        return;
    }
}