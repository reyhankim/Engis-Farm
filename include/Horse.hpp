//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_HORSE_HPP
#define ENGISFARM_HORSE_HPP

#include "MeatProducingFarmAnimal.hpp"

// Class Horse adalah blueprint dari objek FarmProduct
class Horse : public MeatProducingFarmAnimal {
    public:
        // mengembalikan karakter H
        char render() const override;

        // mengembalikan suara kuda misal "Ngihii!"
        string sound() const override;

        // mengembalikan FarmProduct yang behubungan dengan kuda
        Product* getProduct() const override;
};


#endif //ENGISFARM_HORSE_HPP
