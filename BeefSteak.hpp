//
// Created by reyha on 16/03/2019.
//

#ifndef ENGISFARM_BEEFSTEAK_HPP
#define ENGISFARM_BEEFSTEAK_HPP


#include "SideProduct.hpp"

// Class BeefSteak adalah blueprint dari objek SideProduct yang bernama BeefSteak
// BeefSteak = CowMeat + CowMilk
class BeefSteak : public SideProduct {
public:
    // Ctor BeefSteak, menentukan harga BeefSteak
    BeefSteak();
};


#endif //ENGISFARM_BEEFSTEAK_HPP
