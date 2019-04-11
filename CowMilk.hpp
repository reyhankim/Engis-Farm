//
// Created by novendraw on 3/16/19.
//

#ifndef ENGISFARM_COWMILK_HPP
#define ENGISFARM_COWMILK_HPP

#include "FarmProduct.hpp"
#include "Counter.hpp"

// Class CowMilk adalah FarmProduct dari Cow
class CowMilk : public FarmProduct, public Counter<CowMilk> {
    public:
    //Ctor yang mengatur harga awal
        CowMilk();
};

#endif //ENGISFARM_COWMILK_HPP
