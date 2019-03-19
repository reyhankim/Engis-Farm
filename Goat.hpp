//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_GOAT_HPP
#define ENGISFARM_GOAT_HPP

#include "MilkProducingFarmAnimal.hpp"

class Goat : public MilkProducingFarmAnimal {
    public:
        // mengembalikan karakter G
        char render() const override;

        string sound() const;

        Product* getProduct() const override;   
};


#endif //ENGISFARM_GOAT_HPP
