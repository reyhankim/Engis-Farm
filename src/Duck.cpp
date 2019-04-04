#include <iostream>

#include "../include/Duck.hpp"
#include "../include/DuckEgg.hpp"

// mengembalikan karakter D
char Duck::render() const
{
    return 'D';
}

// mengembalikan suara bebek misal "Kwek kwek!"
string Duck::sound() const
{
    return "Kwek kwek!";
}

// mengembalikan FarmProduct yang behubungan dengan bebek
Product* Duck::getProductInteracted() const
{
    return new DuckEgg();
}

// mengembalikan FarmProduct yang dihasilkan jika hewan dibunuh
Product* Duck::getProductKilled() const
{
    return NULL;
}
