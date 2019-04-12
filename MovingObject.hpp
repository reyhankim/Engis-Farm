//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_MOVINGOBJECT_HPP
#define ENGISFARM_MOVINGOBJECT_HPP

#include <string>
#include "Renderable.hpp"
#include "LinkedList.hpp"
#include "Cell.hpp"

using namespace std;

// Class FarmAnimal adalah abstract base class yang memiliki method animal dasar
// dan menjadi dasar pembentukan class animal lainnya.
// TAMBAHAN : Counter pada FarmAnimal untuk menghitung jumlah animal yang masih hidup
class MovingObject : public Renderable {

    public:
        MovingObject();

        MovingObject(int x, int y);

        virtual ~MovingObject();

        // bergerak 
        int move(int direction, LinkedList<Cell*>& field, int fieldXBoundary, int fieldYBoundary);
};


#endif //ENGISFARM_MOVINGOBJECT_HPP
