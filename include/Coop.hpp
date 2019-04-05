//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_COOP_HPP
#define ENGISFARM_COOP_HPP


#include "Land.hpp"

// Class Coop adalah blueprint dari objek turunan "Land" khusus EggProducingFarmAnimal
class Coop : public Land {
public:
    Coop(int axis, int ordinat);
    char render() const override;       // Mengembalikan karakter o
};


#endif //ENGISFARM_COOP_HPP
