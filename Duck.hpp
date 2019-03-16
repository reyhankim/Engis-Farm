//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_DUCK_HPP
#define ENGISFARM_DUCK_HPP

#include "EggProducingFarmAnimal.hpp"

class Duck : public EggProducingFarmAnimal {
    public:
        // mengembalikan karakter D
        char render() const;

        Product* getProduct() const override;
};


#endif //ENGISFARM_DUCK_HPP
