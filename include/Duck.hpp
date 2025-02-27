//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_DUCK_HPP
#define ENGISFARM_DUCK_HPP

#include "EggProducingFarmAnimal.hpp"

// Class Duck adalah blueprint dari objek FarmProduct
class Duck : public EggProducingFarmAnimal {
    public:
        Duck::Duck(int axis, int ordinat);
        // mengembalikan karakter D
        char render() const override;

        // mengembalikan suara bebek misal "Kwek kwek!"
        string sound() const override;

        // mengembalikan FarmProduct yang behubungan dengan bebek
        Product* getProductInteracted() const override;

        // mengembalikan FarmProduct yang dihasilkan jika hewan dibunuh
        Product* getProductKilled() const override;
};


#endif //ENGISFARM_DUCK_HPP
