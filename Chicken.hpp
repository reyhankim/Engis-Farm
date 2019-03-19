//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_CHICKEN_HPP
#define ENGISFARM_CHICKEN_HPP

#include "EggProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"

// Class Chicken adalah blueprint dari objek FarmProduct
class Chicken : public EggProducingFarmAnimal, public MeatProducingFarmAnimal {
    public:
        // mengembalikan karakter C
        char render() const override;

        // mengembalikan suara ayam misal "Petok petok!"
        string sound() const override;

        // mengembalikan FarmProduct yang behubungan dengan ayam
        Product* getProduct() const override;
};

#endif //ENGISFARM_CHICKEN_HPP
