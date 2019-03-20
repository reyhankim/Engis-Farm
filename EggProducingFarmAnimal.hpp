//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_EGGPRODUCINGFARMANIMAL_HPP
#define ENGISFARM_EGGPRODUCINGFARMANIMAL_HPP

#include "FarmAnimal.hpp"

// Class EggProducingFarmAnimal digunakan untuk mengelompokkan animal
class EggProducingFarmAnimal : public FarmAnimal {
    public:
        // method untuk pergerakan animal, hanya dapat bergerak di Coop
        // menerima List of Renderable* untuk mengecek cell yang akan ditempati
        void autoMove(LinkedList<Renderable*> farmMap) override;
};


#endif //ENGISFARM_EGGPRODUCINGFARMANIMAL_HPP
