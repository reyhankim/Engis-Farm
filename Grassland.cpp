#include "Grassland.hpp"

Grassland::Grassland(int x, int y) : Land(x, y) {}

// Mengembalikan karakter -
char Grassland::render() const
{
    return '-';
}