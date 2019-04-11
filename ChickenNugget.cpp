
#include "ChickenNugget.hpp"


// Class ChickenNugget adalah blueprint dari objek SideProduct yang bernama ChickenMeat
// ChickenNugget = ChickenMeat + ChickenEgg
//Ctor yang mengatur harga awal
ChickenNugget::ChickenNugget():SideProduct(), Counter(){
    this->harga = 15000;
}

