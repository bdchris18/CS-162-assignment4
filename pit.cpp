/*********************************************************************
** Program Filename: pit.cpp
** Author: Brandon Christensen
** Date: 5/25/2020
** Description: Functions related to the pit class
** Input: none
** Output: various std::cout statements
*********************************************************************/
#include <iostream>
#include "pit.h"

Pit::Pit(){

}

Pit::~Pit(){
    std::cout << "running pit deconstructor" << std::endl;
    delete this;
}

void Pit::set_name(char name){

}

void Pit::percept(){
    std::cout << "You feel a breeze" << std::endl;
}

void Pit::encounter(){
    std::cout << "You fell into a pit" << std::endl;
}