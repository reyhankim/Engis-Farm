#include "../include/Truck.hpp"

char Truck::render() const
{
    return 'T';
}

int Truck::convertToGold(Product* product)
{
    int profit = product->getHarga();

    return profit;
}