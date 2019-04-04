//
// Created by novendraw on 3/16/19.
//

#ifndef ENGISFARM_GOATMILK_HPP
#define ENGISFARM_GOATMILK_HPP

#include "FarmProduct.hpp"
#include "Counter.hpp"

// Class GoatMilk adalah FarmProduct dari Goat
class GoatMilk : public FarmProduct, public Counter<GoatMilk> {
    public:
    //Ctor yang mengatur harga awal
        GoatMilk();
};

#endif //ENGISFARM_GOATMILK_HPP
