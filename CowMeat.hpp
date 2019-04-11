//
// Created by novendraw on 3/16/19.
//

#ifndef ENGISFARM_COWMEAT_HPP
#define ENGISFARM_COWMEAT_HPP

#include "FarmProduct.hpp"
#include "Counter.hpp"

// Class CowMeat adalah FarmProduct dari Cow
class CowMeat : public FarmProduct, public Counter<CowMeat> {
    public:
    //Ctor yang mengatur harga awal
        CowMeat();
};

#endif //ENGISFARM_COWMEAT_HPP
