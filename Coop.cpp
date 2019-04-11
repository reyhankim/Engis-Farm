#include "Coop.hpp"

Coop::Coop(int axis, int ordinat) : Land(axis, ordinat)
{
    
}

 // Mengembalikan karakter o
char Coop::render() const
{
    return 'o';
}