#include "../include/Well.hpp"

Well::Well(int axis, int ordinat){
    this->x = axis;
    this->y = ordinat;
}

// Mengembalikan karakter W
char Well::render() const
{
    return 'W';
}