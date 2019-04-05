//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_GRASSLAND_HPP
#define ENGISFARM_GRASSLAND_HPP


#include "Land.hpp"

// Class Grassland adalah blueprint dari objek turunan "Land" khusus MilkProducingFarmAnimal
class Grassland : public Land {
public:
    Grassland(int x, int y);
    char render() const override;       // Mengembalikan karakter -
};


#endif //ENGISFARM_GRASSLAND_HPP
