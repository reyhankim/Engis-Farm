//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_GOAT_HPP
#define ENGISFARM_GOAT_HPP

#include "FarmAnimal.hpp"
#include "MilkProducingFarmAnimal.hpp"

// Class Goat adalah blueprint dari objek FarmProduct
class Goat : public MilkProducingFarmAnimal {
    public:
        Goat(int axis, int ordinat);
        // mengembalikan karakter G
        char render() const override;

        // mengembalikan suara kambing misal "Mbheee!"
        string sound() const override;

        // mengembalikan FarmProduct yang behubungan dengan kambing
        Product* getProductInteracted() const override;  

        // mengembalikan FarmProduct yang dihasilkan jika hewan dibunuh
        Product* getProductKilled() const override; 
};


#endif //ENGISFARM_GOAT_HPP
