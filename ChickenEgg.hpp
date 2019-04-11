//
// Created by novendraw on 3/16/19.
//

#ifndef ENGISFARM_CHICKENEGG_HPP
#define ENGISFARM_CHICKENEGG_HPP

#include "FarmProduct.hpp"
#include "Counter.hpp"

// Class ChickenEgg adalah FarmProduct dari Chicken
class ChickenEgg: public FarmProduct, public Counter<ChickenEgg> {
    public:
        //Ctor yang mengatur harga awal
        ChickenEgg();
};

#endif //ENGISFARM_CHICKENEGG_HPP
