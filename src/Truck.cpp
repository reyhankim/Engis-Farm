#include "../include/Truck.hpp"

Truck::Truck(int axis, int ordinat){
    this->x = axis;
    this->y = ordinat;
}

char Truck::render() const
{
    return 'T';
}

int Truck::convertToGold(Product* product)
{
    int profit = product->getHarga();

    return profit;
}