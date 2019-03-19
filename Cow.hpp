//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_COW_HPP
#define ENGISFARM_COW_HPP

#include "MeatProducingFarmAnimal.hpp"
#include "MilkProducingFarmAnimal.hpp"

class Cow : public MeatProducingFarmAnimal, public MilkProducingFarmAnimal {
    public:
        // mengembalikan karakter W
        char render() const override;

        string sound() const;

        Product* getProduct() const override;
};


#endif //ENGISFARM_COW_HPP
