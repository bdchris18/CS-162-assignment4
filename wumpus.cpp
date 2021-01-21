/*********************************************************************
** Program Filename: wumpus.cpp
** Author: Brandon Christensen
** Date: 5/25/2020
** Description: Functions related to the wumpus class
** Input: none
** Output: various std::cout statements
*********************************************************************/
#include <iostream>
#include "wumpus.h"

Wumpus::Wumpus(){

}

Wumpus::~Wumpus(){
    delete this;
}

void Wumpus::set_name(char name){

}

void Wumpus::percept(){
    std::cout << "You smell a terrible stench" << std::endl;
}

void Wumpus::encounter(){
    std::cout << "You were eaten by the wumpus" << std::endl;

}