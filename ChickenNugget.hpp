//
// Created by reyha on 16/03/2019.
//

#ifndef ENGISFARM_CHICKENNUGGET_HPP
#define ENGISFARM_CHICKENNUGGET_HPP

#include "SideProduct.hpp"
#include "Counter.hpp"

// Class ChickenNugget adalah blueprint dari objek SideProduct yang bernama ChickenMeat
// ChickenNugget = ChickenMeat + ChickenEgg
class ChickenNugget : public SideProduct, public Counter<ChickenNugget> {
public:
    // Ctor ChickenNugget, menentukan harga ChickenNugget
    ChickenNugget();
};


#endif //ENGISFARM_CHICKENNUGGET_HPP
