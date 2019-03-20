//
// Created by novendraw on 3/16/19.
//

#ifndef ENGISFARM_DUCKEGG_HPP
#define ENGISFARM_DUCKEGG_HPP

#include "FarmProduct.hpp"
#include "Counter.hpp"

// Class DuckEgg adalah FarmProduct dari Duck
class DuckEgg : public FarmProduct, public Counter<DuckEgg> {
    public:
    //Ctor yang mengatur harga awal
        DuckEgg();
};

#endif //ENGISFARM_DUCKEGG_HPP
