#include "../include/Grassland.hpp"

Grassland::Grassland(int axis, int ordinat){
    this->x = axis;
    this->y = ordinat;
}

// Mengembalikan karakter -
char Grassland::render() const
{
    return '-';
}