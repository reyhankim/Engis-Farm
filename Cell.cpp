#include <iostream>

#include "Cell.hpp"
#include "Land.hpp"

using namespace std;

Cell::Cell(){
}

Cell::Cell(int x, int y) : Renderable(x, y) {
}

Cell::~Cell() {}

bool Cell::isWalkable() const{
    return this->walkable;
}

void Cell::setWalkable(bool input){
    this->walkable = input;
}