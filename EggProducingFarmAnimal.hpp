//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_EGGPRODUCINGFARMANIMAL_HPP
#define ENGISFARM_EGGPRODUCINGFARMANIMAL_HPP

#include "FarmAnimal.hpp"

class EggProducingFarmAnimal : public FarmAnimal {
    public:
        virtual Product* getProduct();
};


#endif //ENGISFARM_EGGPRODUCINGFARMANIMAL_HPP
