//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_BEEFROLADE_HPP
#define ENGISFARM_BEEFROLADE_HPP


#include "SideProduct.hpp"
#include "Counter.hpp"

// Class BeefRolade adalah blueprint dari objek SideProduct yang bernama BeefRolade
// BeefRolade = CowMeat + ChickenEgg
class BeefRolade : public SideProduct, public Counter<BeefRolade> {
public:
    // Ctor BeefRolade, menentukan harga BeefRolade
    BeefRolade();
};


#endif //ENGISFARM_BEEFROLADE_HPP
