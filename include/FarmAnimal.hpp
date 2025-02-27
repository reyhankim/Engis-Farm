//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_FARMANIMAL_HPP
#define ENGISFARM_FARMANIMAL_HPP

#include <string>
#include "Renderable.hpp"
#include "Product.hpp"
#include "LinkedList.hpp"
#include "Counter.hpp"
#include "Scene.hpp"

using namespace std;

// Class FarmAnimal adalah abstract base class yang memiliki method animal dasar
// dan menjadi dasar pembentukan class animal lainnya.
// TAMBAHAN : Counter pada FarmAnimal untuk menghitung jumlah animal yang masih hidup
class FarmAnimal : public Renderable, public Counter<FarmAnimal> {
    
    private:
        const int hungryStart = 0;
        bool interactable;
        int hungryLevel;

    public:
        //CTOR Default
        FarmAnimal();

        // CTOR User defined
        FarmAnimal(string name, bool _interactable);

        // DTOR Virtual
        virtual ~FarmAnimal() = 0;

        // getter
        bool isInteractable() const;
        int getHungryLevel() const;

        // setter
        void setHungryLevel(int _hungryLevel);
        void setInteractable(bool _interactable);

        // method untuk mengurangi nilai hungryLevel animal
        void eat();

        // method pure virtual untuk pergerakan animal
        virtual void autoMove(Scene s) = 0;

        // virtual method untuk mendapatkan suara hewan
        virtual string sound() const = 0;

        // virtual method untuk mengembalikan FarmProduct yang dihasilkan suatu hewan
        // jika diajakberinteraksi 
        virtual Product* getProductInteracted() const = 0;

        // virtual method mengembalikan FarmProduct yang dihasilkan jika hewan dibunuh
        virtual Product* getProductKilled() const = 0;
};


#endif //ENGISFARM_FARMANIMAL_HPP
