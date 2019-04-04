#include <iostream>

#include "../include/Player.hpp"

using namespace std;

Player::Player() : Renderable(){
    this->gold = 0;
    this->currentWater = this->maxWater;
    this->facing = 1;
}

Player::~Player(){
}

char Player::render() const {
    switch(facing){
        case 1 :
            return '^';
            break;
        case 2 :
            return 'V';
            break;
        case 3 :
            return '>';
            break;
        case 4 :
            return '<';
            break;
    }
}

bool Player::isInventoryEmpty(){
    return productInventory.isEmpty();
}

void Player::addToInventory(Product element){
    productInventory.add(element);
}

void Player::removeFromInventory(Product element){
    productInventory.remove(element);
}

Renderable* Player::getInFront(LinkedList<Renderable*> listrender){
    //butuh implementasi lebih lanjut
}

int Player::getGold() const{
    return this->gold;
}

int Player::getFacing() const{
    return this->facing;
}
int Player::getCurrentWater() const{
    return this->currentWater;
}

Product Player::getProductFromInventory(int index){
    return productInventory.get(index);
}

void Player::setGold(int amount){
    gold += amount;
}

void Player::setCurrentWater(int water){
    currentWater += water;
    if(currentWater > maxWater){
        currentWater = maxWater;
    }
}

void Player::move(int direction){
    facing = direction;

    if(facing == 1){
        try{
            if(getY() - 1 < 0){
                throw "Di luar batas permainan";
            }
            
            //if(! getInFront(listrender).isWalkable()){
                //throw "Tidak bisa diakses";
            //}
            
            setY(getY() - 1);
        }
        catch(const char* e){
            cout << e << endl;
        }
    }
    else if(facing == 2){
        try{
            if(this->getY + 1 > 8){ //catatan untuk developer (ubah 8 dengan batas maksimum)
                throw "Di luar batas permainan";
            }
            
            if(! getInFront(listrender).isWalkable()){
                throw "Tidak bisa diakses";
            }

            setY(getY + 1);
        }
        catch(const char* e){
            cout << e << endl;
        }
    }
    else if(facing == 3){
        try{
            if(this->getX + 1 > 8){ //catatan untuk developer (ubah 8 dengan batas maksimum)
                throw "Di luar batas permainan";
            }
            
            if(! getInFront(listrender).isWalkable()){
                throw "Tidak bisa diakses";
            }

            setY(getX + 1);
        }
        catch(const char* e){
            cout << e << endl;
        }
    }
    else if(facing == 4){
        try{
            if(this->getX - 1 < 0){ //catatan untuk developer (ubah 8 dengan batas maksimum)
                throw "Di luar batas permainan";
            }
            
            if(! getInFront(listrender).isWalkable()){
                throw "Tidak bisa diakses";
            }

            setY(getX - 1);
        }
        catch(const char* e){
            cout << e << endl;
        }
    }
}

	
void talk(Renderable* x){
    cout << "Hello" << endl;
}

	
void interact(Renderable*);


void kill(Renderable*);	

void grow();