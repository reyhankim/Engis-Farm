#include <iostream>

#include "../include/Chicken.hpp"
#include "../include/ChickenEgg.hpp"

Chicken::Chicken(int axis, int ordinat){
    this->x = axis;
    this->y = ordinat;
}

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
