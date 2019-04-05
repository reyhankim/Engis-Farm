#include "../include/Coop.hpp"

Coop::Coop(int axis, int ordinat){
    this->x = axis;
    this->y = ordinat;
}

 // Mengembalikan karakter o
char Coop::render() const
{
    return 'o';
}