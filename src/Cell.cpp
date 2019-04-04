#include <iostream>

#include "../include/Cell.hpp"

using namespace std;

Cell::Cell(){
    this->walkable = true;
}

bool Cell::isWalkable() const{
    return this->walkable;
}

void Cell::setWalkable(bool input){
    this->walkable = input;
}