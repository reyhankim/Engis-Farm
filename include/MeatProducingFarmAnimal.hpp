//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_MEATPRODUCINGFARMANIMAL_HPP
#define ENGISFARM_MEATPRODUCINGFARMANIMAL_HPP

#include "FarmAnimal.hpp"
#include "Scene.hpp"

// Class MeatProducingFarmAnimal digunakan untuk mengelompokkan animal
class MeatProducingFarmAnimal : virtual public FarmAnimal {
    public:
        // DTOR Virtual
        virtual ~MeatProducingFarmAnimal();
        // method untuk pergerakan animal, hanya dapat bergerak di Barn
        // menerima List of Renderable* untuk mengecek cell yang akan ditempati
        void autoMove(Scene* s);
};


#endif //ENGISFARM_MEATPRODUCINGFARMANIMAL_HPP
