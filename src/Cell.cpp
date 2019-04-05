#include <iostream>

#include "../include/Cell.hpp"
#include "../include/Land.hpp"

using namespace std;

Cell::Cell(){
    this->walkable = true;
}

Cell::~Cell() {}

bool Cell::isWalkable() const{
    return this->walkable;
}

void Cell::setWalkable(bool input){
    this->walkable = input;
}