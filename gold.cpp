/*********************************************************************
** Program Filename: gold.cpp
** Author: Brandon Christensen
** Date: 5/25/2020
** Description: Functions related to the gold class
** Input: none
** Output: various std::cout statements
*********************************************************************/
#include <iostream>
#include "gold.h"

Gold::Gold(){

}

Gold::~Gold(){
    delete this;
}

void Gold::set_name(char name){

}

void Gold::percept(){
    std::cout << "You see a glimmer nearby" << std::endl;
}

void Gold::encounter(){
    std::cout << "You found the gold" << std::endl;
}