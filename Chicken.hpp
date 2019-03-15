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
        virtual char Render();

        virtual string sound();

        virtual Product* getProduct();
};


#endif //ENGISFARM_CHICKEN_HPP
