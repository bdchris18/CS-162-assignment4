/*********************************************************************
** Program Filename: wumpus_game.cpp
** Author: Brandon Christensen
** Date: 5/25/2020
** Description: Runs "Hunt the wumpus"
** Input: Arguments from user
** Output: 0
*********************************************************************/
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <ncurses.h>
#include "game.h"
#include "room.h"

int main(int argc, char* argv[]){
    if (argc != 3){
        std::cout << "Invalid number of arguments" << std::endl;
        return 1;
    }
    int rows = atoi(argv[1]);
    if (rows < 4){
        std::cout << "Please enter a larger number" << std::endl;
        return 1;
    }
    std::string debug_string = argv[2];
    bool debug;
    if(debug_string == "true"){
        debug = true;
    }
    else if(debug_string == "false"){
        debug = false;
    }
    else{
        std::cout << "Invalid second argument" << std::endl;
        return 1;
    }
    bool program = true;
    bool first_time = true;
    bool game = true;
    bool game2 = true;
    bool play_again = false;
    std::vector<std::vector<Room> > dungeon;
    while(program){
        int arrows = 3;
        bool has_gold = false;
        bool alive = true;
        Game g1;
        Room r1;
        Game g2;
        g1.create_dungeon(rows, dungeon);
        r1.dungeon_setup(rows, dungeon);
        g2 = g1;
        while(first_time == true){
            g1.print_dungeon(rows, dungeon, debug);
            g1.check_near_player(rows, dungeon);
            while(game){
                std::string c;
                std::cout << "Move with w, a, s, d, or shoot with space: " << std::endl;
                getline(std::cin, c);
                if(c == " " && arrows > 0){
                    std::cout << "Which direction?" << std::endl;
                    std::cin >> c;
                    g1.shoot_arrow(r1, c, rows, dungeon, arrows);
                }
                else{
                    g1.move_player(c, rows, dungeon);
                    g1.check_spot(rows, dungeon);
                    if(g1.get_alive() == false){
                        break;
                    }
                    if(g1.get_win() == true){
                        break;
                    }
                    g1.check_near_player(rows, dungeon);
                    g1.print_dungeon(rows, dungeon, debug);
                }
                // g1.print_dungeon(rows, dungeon, debug);
            }
            first_time = false;
        }
        int choice;
        while(first_time != true){
            g2 = g1;
            std::cout << "Would you like to play again?" << std::endl;
            std::cout << "1) same map" << std::endl;
            std::cout << "2) new map" << std::endl;
            std::cout << "3) quit" << std::endl;
            std::cin >> choice;
            if(choice == 1){
                for(int i = 0; i < rows; ++i){
                    for(int n = 0; n < rows; ++n){
                        if(dungeon[i][n].get_has_player()){
                            dungeon[i][n].set_has_player(false);
                        }
                    }
                }
                for(int i = 0; i < rows; ++i){
                    for(int n = 0; n < rows; ++n){
                        if(dungeon[i][n].get_event() == NULL){
                            continue;
                        }
                        else if(dungeon[i][n].get_event()->get_name() == 'e'){
                            dungeon[i][n].set_has_player(true);
                        }
                    }
                }
                g2.print_dungeon(rows, dungeon, debug);
                g2.check_near_player(rows, dungeon);
                while(game){
                    std::string c;
                    std::cout << "Move with w, a, s, d, or shoot with space: " << std::endl;
                    getline(std::cin, c);
                    if(c == " " && arrows > 0){
                        std::cout << "Which direction?" << std::endl;
                        std::cin >> c;
                        g2.shoot_arrow(r1, c, rows, dungeon, arrows);
                    }
                    else{
                        g2.move_player(c, rows, dungeon);
                        g2.check_spot(rows, dungeon);
                        if(g2.get_alive() == false){
                            break;
                        }
                        if(g2.get_win() == true){
                            break;
                        }
                        g2.check_near_player(rows, dungeon);
                        g2.print_dungeon(rows, dungeon, debug);
                    }
                }
            }
            if(choice == 2){
                std::vector<std::vector<Room> > dungeon;
                Game g1;
                Room r1;
                g1.create_dungeon(rows, dungeon);
                r1.dungeon_setup(rows, dungeon);
                g1.print_dungeon(rows, dungeon, debug);
                g1.check_near_player(rows, dungeon);
                while(game){
                    std::string c;
                    std::cout << "Move with w, a, s, d, or shoot with space: " << std::endl;
                    getline(std::cin, c);
                    if(c == " " && arrows > 0){
                        std::cout << "Which direction?" << std::endl;
                        std::cin >> c;
                        g1.shoot_arrow(r1, c, rows, dungeon, arrows);
                    }
                    else{
                        g1.move_player(c, rows, dungeon);
                        g1.check_spot(rows, dungeon);
                        if(g1.get_alive() == false){
                            break;
                        }
                        if(g1.get_win() == true){
                            break;
                        }
                        g1.check_near_player(rows, dungeon);
                        g1.print_dungeon(rows, dungeon, debug);
                    }
                }
            }
            else if(choice == 3){
                first_time = true;
            }
        }
        program = false;
    }
    return 0;
}