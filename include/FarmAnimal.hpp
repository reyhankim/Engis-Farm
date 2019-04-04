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

using namespace std;

// Class FarmAnimal adalah abstract base class yang memiliki method animal dasar
// dan menjadi dasar pembentukan class animal lainnya.
// TAMBAHAN : Counter pada FarmAnimal untuk menghitung jumlah animal yang masih hidup
class FarmAnimal : public Renderable, public Counter<FarmAnimal> {
    
    private :
        const int hungryStart = 0;
    
    protected:
        bool interactable;
        int hungryLevel;
        string name;

    public:
        //CTOR Default
        FarmAnimal();

        // CTOR User defined
        FarmAnimal(string name, bool _interactable);

        // DTOR
        ~FarmAnimal();

        // getter
        bool isInteractable() const;
        int getHungryLevel() const;
        string getName() const;

        // setter
        void setHungryLevel();
        void setName(string name);

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
