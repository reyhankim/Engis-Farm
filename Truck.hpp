//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 11/03/2019

#ifndef ENGISFARM_TRUCK_HPP
#define ENGISFARM_TRUCK_HPP

#include "Renderable.hpp"

class Truck : public Renderable {
	private :
		SideProduct **priceListSideProduct();
		Product **priceListProduct();
		//Product -> Jenis Product -> Int (harga)

	public :
		//CTOR
		Truck();
		
		//DTOR
		~Truck();
		
		//Render
		void render();
		
		//METHOD
		Product getPriceProduct();
		SideProduct getPriceSideProduct();
		void convertToGold(); //proses penjualan
		void setPriceProduct(int price);
		void setPriceSideProduct(int price);
		
		//note to developer : convertToGold memiliki Player::setGold()
};


#endif //ENGISFARM_TRUCK_HPP
