//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 11/03/2019

#ifndef ENGISFARM_TRUCK_HPP
#define ENGISFARM_TRUCK_HPP

#include "Renderable.hpp"

class Truck : public Renderable {
	public :
		//CTOR
		Truck();
		
		//DTOR
		~Truck();
		
		//Render
		void render();
		
		//METHOD
		void convertToGold(Product product); //proses penjualan
		
		//note to developer : convertToGold memiliki Player::setGold()
};


#endif //ENGISFARM_TRUCK_HPP
