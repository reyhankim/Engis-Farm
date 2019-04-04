//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_DUCK_HPP
#define ENGISFARM_DUCK_HPP

#include "EggProducingFarmAnimal.hpp"

// Class Duck adalah blueprint dari objek FarmProduct
class Duck : public EggProducingFarmAnimal {
    public:
        // mengembalikan karakter D
        char render() const override;

        // mengembalikan suara bebek misal "Kwek kwek!"
        string sound() const override;

        // mengembalikan FarmProduct yang behubungan dengan bebek
        Product* getProduct() const override;
};


#endif //ENGISFARM_DUCK_HPP
