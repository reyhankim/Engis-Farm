#include <iostream>

#include "FarmAnimal.hpp"

using namespace std;

FarmAnimal::FarmAnimal(string name, bool _interactable){
    this->name = name;
    this->interactable = _interactable;
    this->hungryLevel = this->hungryStart;
}

FarmAnimal::~FarmAnimal(){
    cout << name << " is dead" << endl;
}

bool FarmAnimal::isInteractable() const{
    return this->interactable;
}

int FarmAnimal::getHungryLevel() const{
    return this->
}

void FarmAnimal::setHungryLevel(){
    this->hungryLevel = this->hungryStart;
}

void FarmAnimal::setName(string name){
    this->name = name;
}

void FarmAnimal::eat(){
    this->hungryLevel--;
}