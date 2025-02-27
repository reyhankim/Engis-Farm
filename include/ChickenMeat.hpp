//
// Created by novendraw on 3/16/19.
//

#ifndef ENGISFARM_CHICKENMEAT_HPP
#define ENGISFARM_CHICKENMEAT_HPP

#include "FarmProduct.hpp"
#include "Counter.hpp"

// Class ChickenMeat adalah FarmProduct dari Chicken
class ChickenMeat : public FarmProduct, public Counter<ChickenMeat> {
    public:
        //Ctor yang mengatur harga awal
        ChickenMeat();
};

#endif //ENGISFARM_CHICKENMEAT_HPP
