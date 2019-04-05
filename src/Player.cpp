#include <iostream>
#include "../include/Player.hpp"
#include "../include/LeafInclude.hpp"
#include "../include/Land.hpp"
#include "../include/Scene.hpp"

using namespace std;

Player::Player() : Renderable(){
    this->gold = 0;
    this->currentWater = this->maxWater;
    this->facing = 1;
}

Player::~Player(){
    delete &productInventory;
}

char Player::render() const {
    switch(facing){
        case 1 :
            return '^';
        case 2 :
            return 'V';
        case 3 :
            return '>';
        case 4 :
            return '<';
    }
}

bool Player::isInventoryEmpty(){
    return productInventory.isEmpty();
}

void Player::addToInventory(Product* element){
    productInventory.add(element);
}

void Player::removeFromInventory(Product* element){
    productInventory.remove(element);
}

Renderable* Player::getInFront(Scene s){
    int i=0;
    bool found = false;
    while(!found && i<s.field.Count){
        Node *test = s.field.head;
        if(test->
    }
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

Product* Player::getProductFromInventory(int index){
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

void Player::move(int direction, Scene s){
    if(direction == 1){
        try{
            if(getY() - 1 < 0){
                throw "Di luar batas permainan";
            }
            
            if(! getInFront(s).isWalkable()){
                throw "Tidak bisa diakses";
            }
            
            setY(getY() - 1);
        }
        catch(const char* e){
            cout << e << endl;
        }
    }
    else if(direction == 2){
        try{
            if(this->getY() + 1 > 8){ //catatan untuk developer (ubah 8 dengan batas maksimum)
                throw "Di luar batas permainan";
            }
            
            if(!getInFront()->isWalkable()){
                throw "Tidak bisa diakses";
            }

            setY(getY() + 1);
        }
        catch(const char* e){
            cout << e << endl;
        }
    }
    else if(direction == 3){
        try{
            if(this->getX() + 1 > 8){ //catatan untuk developer (ubah 8 dengan batas maksimum)
                throw "Di luar batas permainan";
            }
            
            if(! getInFront(listrender).isWalkable()){
                throw "Tidak bisa diakses";
            }

            setY(getX() + 1);
        }
        catch(const char* e){
            cout << e << endl;
        }
    }
    else if(direction == 4){
        try{
            if(this->getX() - 1 < 0){ //catatan untuk developer (ubah 8 dengan batas maksimum)
                throw "Di luar batas permainan";
            }
            
            if(! getInFront(listrender).isWalkable()){
                throw "Tidak bisa diakses";
            }

            setY(getX() - 1);
        }
        catch(const char* e){
            cout << e << endl;
        }
    }

    facing = direction;
}

template<typename T>	
void Player::talk<T>(T* x){
    cout << "Hello" << endl;
    FarmAnimal *benda;
    if((benda = dynamic_cast<FarmAnimal*>(x)) != NULL){
        cout << benda->sound() << endl;
    }
}

template<>
void Player::interact<EggProducingFarmAnimal>(EggProducingFarmAnimal* x){
    Chicken *ayam;
    Duck *bebek;
    if((ayam = dynamic_cast<Chicken*>(x)) != NULL){
        addToInventory(new ChickenEgg());
    }
    else if((bebek = dynamic_cast<Duck*>(x)) != NULL){
        addToInventory(new DuckEgg());
    }
}

template<>
void Player::interact<MilkProducingFarmAnimal>(MilkProducingFarmAnimal* x){
    Goat *kambing;
    Cow *sapi;
    if((kambing = dynamic_cast<Goat*>(x)) != NULL){
        addToInventory(new GoatMilk());
    }
    else if((sapi = dynamic_cast<Cow*>(x)) != NULL){
        addToInventory(new CowMilk());
    }
}

template<typename T>
void Player::interact<T>(T* x){
    //do nothing
}

template<>
void Player::kill<MeatProducingFarmAnimal>(MeatProducingFarmAnimal* x){
    Chicken *ayam;
    Cow *sapi;
    Horse *kuda;
    Swine *haram;

    if((ayam = dynamic_cast<Chicken*>(x)) != NULL){
        addToInventory(new ChickenMeat());
    }
    else if((sapi = dynamic_cast<Cow*>(x)) != NULL){
        addToInventory(new CowMeat());
    }
    else if((kuda = dynamic_cast<Horse*>(x)) != NULL){
        addToInventory(new HorseMeat());
    }
    else if((haram = dynamic_cast<Swine*>(x)) != NULL){
        addToInventory(new SwineMeat());
    }
}

template <typename T>
void Player::kill<T>(T* x){
    //do nothing
}

template <typename T>
void Player::grow<T>(T* r){
    Land *lahan;
    if(lahan = dynamic_cast<Land*>(r)){
        r->setGrass(true);
    }
}