#include <iostream>

#include "../include/Swine.hpp"
#include "../include/ChickenEgg.hpp"

// mengembalikan karakter S
char Swine::render() const
{
    return 'S';
}

 // mengembalikan suara babi misal "Ngookk"
string Swine::sound() const
{
    return "Ngookk";
}

// mengembalikan FarmProduct yang behubungan dengan babi
Product* Swine::getProductInteracted() const
{
    return new ChickenEgg();
}

// mengembalikan FarmProduct yang dihasilkan jika hewan dibunuh
Product* Swine::getProductKilled() const
{
    return NULL;
}
