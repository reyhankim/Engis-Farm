#include <iostream>

#include "../include/Horse.hpp"
#include "../include/GoatMilk.hpp"

// mengembalikan karakter D
char Horse::render() const
{
    return 'G';
}

// mengembalikan suara kambing misal "Mbheee!"
string Horse::sound() const
{
    return "Mbheee!";
}

// mengembalikan FarmProduct yang behubungan dengan kambing
Product* Horse::getProductInteracted() const
{
    return new GoatMilk();
}

// mengembalikan FarmProduct yang dihasilkan jika hewan dibunuh
Product* Horse::getProductKilled() const
{
    return NULL;
}
