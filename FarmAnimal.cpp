#include <iostream>

#include "FarmAnimal.hpp"

using namespace std;

FarmAnimal::FarmAnimal(){
    this->interactable = true;
    this->hungryLevel = this->hungryStart;
}

FarmAnimal::FarmAnimal(int x, int y) : MovingObject(x, y) {
    this->interactable = true;
    this->hungryLevel = this->hungryStart;
}

bool FarmAnimal::isInteractable() const{
    return this->interactable;
}

int FarmAnimal::getHungryLevel() const{
    return this->hungryLevel;
}

void FarmAnimal::setHungryLevel(int _hungryLevel){
    this->hungryLevel = _hungryLevel;
}

void FarmAnimal::setInteractable(bool _interactable){
    this->interactable = _interactable;
}

void FarmAnimal::eat(){
    this->setHungryLevel(0);
}