#include "../include/ChickenNugget.hpp"
#include "../include/BeefRolade.hpp"
#include "../include/BeefSteak.hpp"
#include "../include/ChickenEgg.hpp"
#include "../include/ChickenMeat.hpp"
#include "../include/CowMeat.hpp"
#include "../include/CowMilk.hpp"
#include "../include/Mixer.hpp"
#include <iostream>
#include <vector>

using namespace std;

Mixer::Mixer(int axis, int ordinat){
    this->x = axis;
    this->y = ordinat;
}

char Mixer::render() const{
    return 'X';
}

template <>
SideProduct* Mixer::mix<CowMeat, ChickenEgg>(CowMeat bahan1, ChickenEgg bahan2){
    // CowMeat + ChickenEgg = BeefRolade
    return new BeefRolade();
}

template <>
SideProduct* Mixer::mix<ChickenEgg, CowMeat>(ChickenEgg bahan1, CowMeat bahan2){
    return new BeefRolade();
}

template <>
SideProduct* Mixer::mix<ChickenMeat, ChickenEgg>(ChickenMeat bahan1, ChickenEgg bahan2){
    return new ChickenNugget();
}

template <>
SideProduct* Mixer::mix<ChickenEgg, ChickenMeat>(ChickenEgg bahan1, ChickenMeat bahan2){
    return new ChickenNugget();
}

template <>
SideProduct* Mixer::mix<CowMeat, CowMilk>(CowMeat bahan1, CowMilk bahan2){
    return new BeefSteak();
}

template <>
SideProduct* Mixer::mix<CowMilk, CowMeat>(CowMilk bahan1, CowMeat bahan2){
    return new BeefSteak();
}

//
template <typename U, typename V>
SideProduct* Mixer::mix<U, V>(U bahan1, V bahan2){
    return NULL;
}