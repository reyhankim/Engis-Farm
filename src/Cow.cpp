#include <iostream>

#include "../include/Cow.hpp"
#include "../include/CowMilk.hpp"
#include "../include/CowMeat.hpp"
#include "../include/Barn.hpp"
#include "../include/Grassland.hpp"

Cow::Cow(int axis, int ordinat){
    this->x = axis;
    this->y = ordinat;
}

// mengembalikan karakter W
char Cow::render() const
{
    return 'W';
}

// mengembalikan suara sapi misal "Moo!"
string Cow::sound() const
{
    return "Moo!";
}

// mengembalikan FarmProduct yang behubungan dengan sapi
Product* Cow::getProductInteracted() const
{
    return new CowMilk();
}

// mengembalikan FarmProduct yang dihasilkan jika hewan dibunuh
Product* Cow::getProductKilled() const
{
    return new CowMeat();
}

void Cow::autoMove(Scene *s) {
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
            if (Barn *f = dynamic_cast<Barn *>(s->field.get(i))) {
                // valid move
            } else if (Grassland *f = dynamic_cast<Grassland *>(s->field.get(i))) {
                // Valid move
            } else {validMove = 0;}
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
    if (s->farmMap[targetX][targetY] != 'o') {
        validMove != 1;
    }

    if (validMove == 1) {
        this->setX(targetX);
        this->setY(targetY);
    }
}
