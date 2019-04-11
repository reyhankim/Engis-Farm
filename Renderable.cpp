#include <iostream>

#include "Renderable.hpp"

using namespace std;

Renderable::Renderable(){
    //apakah butuh ctor default?
}

Renderable::Renderable(int x, int y){
    this->x = x;
    this->y = y;
}

Renderable::~Renderable() {}

void Renderable::setX(int x){
    this->x = x;
}

void Renderable::setY(int y){
    this->y = y;
}

int Renderable::getX() const{
    return this->x;
}

int Renderable::getY() const{
    return this->y;
}