//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_HORSE_HPP
#define ENGISFARM_HORSE_HPP

#include "MeatProducingFarmAnimal.hpp"

class Horse : public MeatProducingFarmAnimal {
    public:
        // mengembalikan karakter H
        char render() const;

        string sound() const;

        Product* getProduct() const override;
};


#endif //ENGISFARM_HORSE_HPP
