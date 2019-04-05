
#include "../include/MeatProducingFarmAnimal.hpp"
#include "../include/Scene.hpp"

// Class MeatProducingFarmAnimal digunakan untuk mengelompokkan animal

        // DTOR Virtual
        MeatProducingFarmAnimal::~MeatProducingFarmAnimal(){

}
        // method untuk pergerakan animal, hanya dapat bergerak di Barn
        // menerima List of Renderable* untuk mengecek cell yang akan ditempati
void MeatProducingFarmAnimal::autoMove(Scene* s){
    int targetX, targetY;
    int direction = rand() % 5;
    int validMove = 1;

    if (direction == 1) {           // atas
        targetX = this->getX();
        targetY = this->getY()-1;
    } else if (direction == 2){     // bawah
        targetX = this->getX();
        targetY = this->getY()+1;
    } else if (direction == 3) {    // kiri
        targetX = this->getX()-1;
        targetY = this->getY();
    } else if (direction == 4){                                // kanan
        targetX = this->getX()+1;
        targetY = this->getY();
    }

    int i = 0; int found = 0;
    while (i < s->farmMapHeight*s->farmMapWidth && found == 0) {
        if (s->field.get(i)->getX() == targetX && s->field.get(i)->getY() == targetY) {
            if (Cell *f = dynamic_cast<Cell *>(s->field.get(i))) {
                // valid move
            } else { validMove = 0; }
            found = 1;
        }
        i++;
    }

    i = 0; found = 0;
    while (i < Counter<FarmAnimal>::objects_alive && found == 0) {
        if (s->animals.get(i)->getX() == targetX && s->animals.get(i)->getY() == targetY) {
            validMove = 0;
            found = 1;
        }
        i++;
    }

    if (s->player.getX() == targetX && s->player.getY() == targetY) {
        validMove = 0;
    }

    // QUICK
    if (s->farmMap[targetX][targetY] != 'x') {
        validMove != 1;
    }

    if (validMove == 1) {
        this->setX(targetX);
        this->setY(targetY);
    }
}
