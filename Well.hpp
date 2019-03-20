//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 11/03/2019

#ifndef ENGISFARM_WELL_HPP
#define ENGISFARM_WELL_HPP

#include "Facility.hpp"

// Class Truck adalah blueprint dari objek yang digunakan untuk menambah air yang dibawa player
class Well : public Facility {
	public :
		char render() const override;		// Mengembalikan karakter W
};


#endif //ENGISFARM_WELL_HPP
