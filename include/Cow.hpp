//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_COW_HPP
#define ENGISFARM_COW_HPP

#include "MeatProducingFarmAnimal.hpp"
#include "MilkProducingFarmAnimal.hpp"

// Class Cow adalah blueprint dari objek FarmProduct
class Cow : public MeatProducingFarmAnimal, public MilkProducingFarmAnimal {
    public:
        // mengembalikan karakter W
        char render() const override;

        // mengembalikan suara sapi misal "Moo!"
        string sound() const override;

        // mengembalikan FarmProduct yang behubungan dengan sapi
        Product* getProductInteracted() const override;

        // mengembalikan FarmProduct yang dihasilkan jika hewan dibunuh
        Product* getProductKilled() const override;
};


#endif //ENGISFARM_COW_HPP
