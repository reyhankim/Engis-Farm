//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_FARMANIMAL_HPP
#define ENGISFARM_FARMANIMAL_HPP

#include <string>
#include "Renderable.hpp"
#include "Product.hpp"

using namespace std;

class FarmAnimal : public Renderable {
    protected:
        bool interactable;
        bool hungry;
        void eat();
        void autoMove();

    public:
        // CTOR
        FarmAnimal();

        bool isInteractable();

        bool isHungry();

        virtual string sound() = 0;

        virtual Product* getProduct() = 0;
};


#endif //ENGISFARM_FARMANIMAL_HPP
