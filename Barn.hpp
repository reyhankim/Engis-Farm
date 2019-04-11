//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_BARN_HPP
#define ENGISFARM_BARN_HPP
#include "Land.hpp"

// Class Barn adalah blueprint dari objek turunan "Land" khusus MeatProducingFarmAnimal
class Barn : public Land {
public:
    Barn(int axis, int ordinat);
    
    char render() const override;       // Mengembalikan karakter x
};


#endif //ENGISFARM_BARN_HPP
