//
// Created by novendraw on 3/16/19.
//

#ifndef ENGISFARM_HORSEMEAT_HPP
#define ENGISFARM_HORSEMEAT_HPP

#include "FarmProduct.hpp"
#include "Counter.hpp"

// Class HorseMeat adalah FarmProduct dari Horse
class HorseMeat : public FarmProduct, public Counter<HorseMeat> {
    public:
    //Ctor yang mengatur harga awal
        HorseMeat();
};

#endif //ENGISFARM_HORSEMEAT_HPP
