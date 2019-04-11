#include "Well.hpp"

Well::Well(int axis, int ordinat) : Facility(axis,ordinat) {}

// Mengembalikan karakter W
char Well::render() const
{
    return 'W';
}