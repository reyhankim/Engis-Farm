//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_GOAT_HPP
#define ENGISFARM_GOAT_HPP

#include "MilkProducingFarmAnimal.hpp"

class Goat : public MilkProducingFarmAnimal {
    public:
        // mengembalikan karakter G
        virtual char Render();

        virtual string sound();

        virtual Product* getProduct();
};


#endif //ENGISFARM_GOAT_HPP
