#include <iostream>

#include "../include/Cow.hpp"
#include "../include/CowMilk.hpp"
#include "../include/CowMeat.hpp"

// mengembalikan karakter W
char Cow::render() const
{
    return 'W';
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
