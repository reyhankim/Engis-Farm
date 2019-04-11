#include <iostream>

#include "Chicken.hpp"
#include "ChickenEgg.hpp"

Chicken::Chicken(int axis, int ordinat) : FarmAnimal(axis, ordinat) {}

// mengembalikan karakter C
char Chicken::render() const
{
    return 'C';
}

 // mengembalikan suara ayam misal "Petok petok!"
string Chicken::sound() const
{
    return "Petok petok!";
}

// mengembalikan FarmProduct yang behubungan dengan ayam
Product* Chicken::getProductInteracted() const
{
    return new ChickenEgg();
}

// mengembalikan FarmProduct yang dihasilkan jika hewan dibunuh
Product* Chicken::getProductKilled() const
{
    return NULL;
}
