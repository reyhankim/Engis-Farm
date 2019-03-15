//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_SWINE_HPP
#define ENGISFARM_SWINE_HPP

#include "MeatProducingFarmAnimal.hpp"

class Swine : public MeatProducingFarmAnimal {
    public:
        // mengembalikan karakter S
        virtual char Render();

        virtual string sound();

        virtual Product* getProduct();
};


#endif //ENGISFARM_SWINE_HPP
