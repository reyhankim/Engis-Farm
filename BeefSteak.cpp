
#include "BeefSteak.hpp"

// Class BeefSteak adalah blueprint dari objek SideProduct yang bernama BeefSteak
// BeefSteak = CowMeat + CowMilk
//Ctor yang mengatur harga awal
BeefSteak::BeefSteak():SideProduct(), Counter(){
    this->harga = 22000;
}
