//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_FARMANIMAL_HPP
#define ENGISFARM_FARMANIMAL_HPP

#include <string>
#include "Renderable.hpp"
#include "Product.hpp"
#include "LinkedList.hpp"

using namespace std;

// Class FarmAnimal adalah abstract base class yang memiliki method animal dasar
// dan menjadi dasar pembentukan class animal lainnya.
class FarmAnimal : public Renderable {
    protected:
        bool interactable;
        int hungryLevel;

    public:
        // CTOR User defined
        FarmAnimal(bool _interactable);

        // getter
        bool isInteractable() const;
        int getHungryLevel() const;

        // setter
        int setHungryLevel() const;

        // method untuk mengurangi nilai hungryLevel animal
        void eat();

        // method pure virtual untuk pergerakan animal
        // menerima List of Renderable* untuk mengecek cell yang akan ditempati
        virtual void autoMove(LinkedList<Renderable*> farmMap) = 0;

        // virtual method untuk mendapatkan suara hewan
        virtual string sound() const = 0;

        // virtual method untuk mengembalikan FarmProduct yang dihasilkan suatu hewan
        virtual Product* getProduct() const = 0;
};


#endif //ENGISFARM_FARMANIMAL_HPP
