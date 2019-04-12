#include <iostream>

#include "Cell.hpp"
#include "Land.hpp"

using namespace std;

Cell::Cell(int x, int y) : Renderable(x, y) {
}

bool Cell::isWalkable() const{
    return this->walkable;
}

void Cell::setWalkable(bool input){
    this->walkable = input;
}