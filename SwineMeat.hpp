//
// Created by novendraw on 3/16/19.
//

#ifndef ENGISFARM_SWINEMEAT_HPP
#define ENGISFARM_SWINEMEAT_HPP

#include "FarmProduct.hpp"
#include "Counter.hpp"

// Class SwineMeat adalah FarmProduct dari Swine
class SwineMeat : public FarmProduct, public Counter<SwineMeat> {
    public:
        //Ctor yang mengatur harga awal
        SwineMeat();
};

#endif //ENGISFARM_SWINEMEAT_HPP
