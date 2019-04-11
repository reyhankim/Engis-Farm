#include "Barn.hpp"

Barn::Barn(int axis, int ordinat) : Land(axis, ordinat) {}

 // Mengembalikan karakter x
char Barn::render() const
{
    return 'x';
}