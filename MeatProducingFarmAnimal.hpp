//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_MEATPRODUCINGFARMANIMAL_HPP
#define ENGISFARM_MEATPRODUCINGFARMANIMAL_HPP

#include "FarmAnimal.hpp"

class MeatProducingFarmAnimal : public FarmAnimal {
    public:
        virtual Product* getProduct() const;
};


#endif //ENGISFARM_MEATPRODUCINGFARMANIMAL_HPP
