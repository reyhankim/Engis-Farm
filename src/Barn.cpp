#include "../include/Barn.hpp"

Barn::Barn(int axis, int ordinat){
    this->x = axis;
    this->y = ordinat;
}
 // Mengembalikan karakter x
char Barn::render() const
{
    return 'x';
}