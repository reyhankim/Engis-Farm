#include <iostream>
#include "Facility.hpp"

using namespace std;

Facility::Facility(int x, int y) : Cell(x, y){
    this->walkable = false;
}

Facility::~Facility() {}