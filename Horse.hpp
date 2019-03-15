//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_HORSE_HPP
#define ENGISFARM_HORSE_HPP

#include "MeatProducingFarmAnimal.hpp"

class Horse : public MeatProducingFarmAnimal {
    public:
        // mengembalikan karakter H
        virtual char Render();

        virtual string sound();

        virtual Product* getProduct();
};


#endif //ENGISFARM_HORSE_HPP
