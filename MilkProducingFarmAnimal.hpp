//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_MILKPRODUCINGFARMANIMAL_HPP
#define ENGISFARM_MILKPRODUCINGFARMANIMAL_HPP

#include "FarmAnimal.hpp"
#include "Scene.hpp"

// Class MilkProducingFarmAnimal digunakan untuk mengelompokkan animal
class MilkProducingFarmAnimal : virtual public FarmAnimal {
    public:
        // DTOR Virtual
        virtual ~MilkProducingFarmAnimal();
};


#endif //ENGISFARM_MILKPRODUCINGFARMANIMAL_HPP
