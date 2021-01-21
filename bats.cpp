/*********************************************************************
** Program Filename: bats.cpp
** Author: Brandon Christensen
** Date: 5/25/2020
** Description: Functions related to the bats class
** Input: none
** Output: various std::cout statements
*********************************************************************/
#include <iostream>
#include "bats.h"

Bats::Bats(){

}

Bats::~Bats(){
    delete this;
}

void Bats::set_name(char name){

}

void Bats::percept(){
    std::cout << "You hear wings flapping nearby" << std::endl;
}

void Bats::encounter(){
    std::cout << "Bats carried you to a new room" << std::endl;
}