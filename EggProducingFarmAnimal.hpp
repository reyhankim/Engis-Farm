//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_EGGPRODUCINGFARMANIMAL_HPP
#define ENGISFARM_EGGPRODUCINGFARMANIMAL_HPP

#include "FarmAnimal.hpp"
#include "Scene.hpp"

// Class EggProducingFarmAnimal digunakan untuk mengelompokkan animal
class EggProducingFarmAnimal : virtual public FarmAnimal {
    public:
        // DTOR Virtual
        virtual ~EggProducingFarmAnimal();
        // method untuk pergerakan animal, hanya dapat bergerak di Coop
        // menerima List of Renderable* untuk mengecek cell yang akan ditempati
};


#endif //ENGISFARM_EGGPRODUCINGFARMANIMAL_HPP
