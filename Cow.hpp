//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_COW_HPP
#define ENGISFARM_COW_HPP

#include "MeatProducingFarmAnimal.hpp"
#include "MilkProducingFarmAnimal.hpp"

class Cow : public MeatProducingFarmAnimal, public MilkProducingFarmAnimal {
    public:
        // mengembalikan karakter W
        virtual char Render();

        virtual string sound();

        virtual Product* getProduct();
};


#endif //ENGISFARM_COW_HPP
