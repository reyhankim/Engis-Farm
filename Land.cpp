#include "Land.hpp"
#include <iostream>

using namespace std;

Land::Land() : Cell(){
    walkable = true;
    randomGrass();
}

Land::Land(int x, int y) : Cell(x, y){
    walkable = true;
    randomGrass();
}

Land::~Land() {}

void Land::randomGrass(){
    if(rand() % 100 < Land::chanceGrassed){
        setGrass(true);
    }
}

void Land::setGrass(bool input){
    grassed = input;
}

bool Land::getGrass() const{
    return grassed;
}