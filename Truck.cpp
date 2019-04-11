#include "Truck.hpp"

Truck::Truck(int axis, int ordinat) : Facility(axis,ordinat)
{

}

Truck::~Truck() {}

char Truck::render() const
{
    return 'T';
}

int Truck::convertToGold(Product* product)
{
    int profit = product->getHarga();

    return profit;
}