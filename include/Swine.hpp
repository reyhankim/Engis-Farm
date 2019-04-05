//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_SWINE_HPP
#define ENGISFARM_SWINE_HPP

#include "MeatProducingFarmAnimal.hpp"

// Class Swine adalah blueprint dari objek FarmProduct
class Swine : public MeatProducingFarmAnimal {
    public:
        Swine(int axis, int ordinat);
        // mengembalikan karakter S
        char render() const override;

        // mengembalikan suara babi misal "Ngookk"
        string sound() const override;

        // mengembalikan FarmProduct yang behubungan dengan babi
        Product* getProductInteracted() const override;

        // mengembalikan FarmProduct yang dihasilkan jika hewan dibunuh
        Product* getProductKilled() const override;
};


#endif //ENGISFARM_SWINE_HPP
