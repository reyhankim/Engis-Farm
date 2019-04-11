#include <iostream>

#include "Goat.hpp"
#include "GoatMilk.hpp"

Goat::Goat(int axis, int ordinat) : FarmAnimal(axis, ordinat) {

}

// mengembalikan karakter D
char Goat::render() const
{
    return 'G';
}

// mengembalikan suara kambing misal "Mbheee!"
string Goat::sound() const
{
    return "Mbheee!";
}

// mengembalikan FarmProduct yang behubungan dengan kambing
Product* Goat::getProductInteracted() const
{
    return new GoatMilk();
}

// mengembalikan FarmProduct yang dihasilkan jika hewan dibunuh
Product* Goat::getProductKilled() const
{
    return NULL;
}
