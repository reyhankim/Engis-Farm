#include <iostream>

#include "Cow.hpp"
#include "CowMilk.hpp"
#include "CowMeat.hpp"

Cow::Cow(int axis, int ordinat): FarmAnimal(axis, ordinat){

}

// mengembalikan karakter C
char Cow::render() const
{
    return 'C';
}

// mengembalikan suara sapi misal "Moo!"
string Cow::sound() const
{
    return "Moo!";
}

// mengembalikan FarmProduct yang behubungan dengan sapi
Product* Cow::getProductInteracted() const
{
    return new CowMilk();
}

// mengembalikan FarmProduct yang dihasilkan jika hewan dibunuh
Product* Cow::getProductKilled() const
{
    return new CowMeat();
}
