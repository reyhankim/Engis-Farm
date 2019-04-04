#include "../include/ChickenNugget.hpp"
#include "../include/BeefRolade.hpp"
#include "../include/BeefSteak.hpp"
#include "../include/ChickenEgg.hpp"
#include "../include/ChickenMeat.hpp"
#include "../include/CowMeat.hpp"
#include "../include/CowMilk.hpp"
#include "../include/Mixer.hpp"
#include <iostream>
#include <vector>

using namespace std;

Mixer::Mixer(){
    listSideProduct = new Product* [row];
    for(int i=0;i<row;i++){
        listSideProduct[i] = new Product [3];
    }

    listSideProduct[0][0] = new ChickenNugget();
    listSideProduct[0][1] = new ChickenEgg();
    listSideProduct[0][2] = new ChickenMeat();

    listSideProduct[1][0] = new BeefRolade();
    listSideProduct[1][1] = new CowMeat();
    listSideProduct[1][2] = new ChickenEgg();

    listSideProduct[2][0] = new BeefSteak();
    listSideProduct[2][1] = new CowMeat();
    listSideProduct[2][2] = new CowMilk();
}

Mixer::~Mixer(){
    for(int i=0;i<row;i++){
        delete [] listSideProduct[i];
    }
    delete [] listSideProduct;
}

char Mixer::render() const override{
    return 'X';
}

SideProduct Mixer::mix(FarmProduct bahan1, FarmProduct bahan2){
    bool found = false;
    for(int i=0;i<row;i++){
        if(bahan1 = static_cast<FarmProduct>(listSideProduct[i][1]) != NULL){
            if(bahan2 = static_cast<FarmProduct>(listSideProduct[i][2]) != NULL){
                found = true;
                return listSideProduct[i][0];
            }
        }
    }

    if(!found){
        return NULL;
    }
}