//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_CHICKEN_HPP
#define ENGISFARM_CHICKEN_HPP

#include "EggProducingFarmAnimal.hpp"
#include "MeatProducingFarmAnimal.hpp"

class Chicken : public EggProducingFarmAnimal, public MeatProducingFarmAnimal {
    public:
        // mengembalikan karakter C
        char render() const;

        string sound() const;

        Product* getProduct() const override;
};


#endif //ENGISFARM_CHICKEN_HPP
