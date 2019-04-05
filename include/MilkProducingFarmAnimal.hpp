//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_MILKPRODUCINGFARMANIMAL_HPP
#define ENGISFARM_MILKPRODUCINGFARMANIMAL_HPP

#include "FarmAnimal.hpp"

// Class MilkProducingFarmAnimal digunakan untuk mengelompokkan animal
class MilkProducingFarmAnimal : public FarmAnimal {
    public:
        // DTOR Virtual
        virtual ~MilkProducingFarmAnimal();
        // method untuk pergerakan animal, hanya dapat bergerak di Grassland
        // menerima List of Renderable* untuk mengecek cell yang akan ditempati
        void autoMove() override;
};


#endif //ENGISFARM_MILKPRODUCINGFARMANIMAL_HPP
