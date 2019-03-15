//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_MILKPRODUCINGFARMANIMAL_HPP
#define ENGISFARM_MILKPRODUCINGFARMANIMAL_HPP

#include "FarmAnimal.hpp"

class MilkProducingFarmAnimal : public FarmAnimal {
    public:
        virtual Product* getProduct();
};


#endif //ENGISFARM_MILKPRODUCINGFARMANIMAL_HPP
