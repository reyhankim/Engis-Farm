//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 11/03/2019

#ifndef ENGISFARM_TRUCK_HPP
#define ENGISFARM_TRUCK_HPP

#include "Product.hpp"
#include "Facility.hpp"

// Class Truck adalah blueprint dari objek yang digunakan untuk menjual Product
class Truck : public Facility {
	public :
		//CTOR
		Truck();
		
		//DTOR
		~Truck();
		
		//Render
		char render() const override;			// Mengembalikan karakter T
		
		//METHOD
		void convertToGold(Product product); 	//proses penjualan, menghasilkan gold dengan menjual product yang dipilih
		
		//note to developer : convertToGold memiliki Player::setGold()
};


#endif //ENGISFARM_TRUCK_HPP
