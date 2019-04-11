//
// Created by novendraw on 3/16/19.
//

#include "ChickenEgg.hpp"

// Class ChickenEgg adalah FarmProduct dari Chicken

//Ctor yang mengatur harga awal
ChickenEgg::ChickenEgg():FarmProduct(), Counter(){
    this->harga = 5000;
}