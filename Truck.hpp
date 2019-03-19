//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 11/03/2019

#ifndef ENGISFARM_TRUCK_HPP
#define ENGISFARM_TRUCK_HPP

#include "Product.hpp"
#include "Facility.hpp"

class Truck : public Facility {
	public :
		//CTOR
		Truck();
		
		//DTOR
		~Truck();
		
		//Render
		char render() const override;
		
		//METHOD
		void convertToGold(Product product); //proses penjualan
		
		//note to developer : convertToGold memiliki Player::setGold()
};


#endif //ENGISFARM_TRUCK_HPP
