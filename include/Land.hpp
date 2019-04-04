//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 15/03/2019

#ifndef ENGISFARM_LAND_HPP
#define ENGISFARM_LAND_HPP


#include "Cell.hpp"

// Class Land adalah blueprint dari objek turunan "Cell" yang dapat ditempati oleh Animal atau Player
class Land : public Cell {
	protected :
		bool grassed;           // Menyimpan boolean untuk mengetahui Land tersebut ditumbuhi rumput atau tidak
		// menentukan secara acak apakah Land akan berrumput (dipanggil oleh CTOR)
		void randomGrass();
		int const chanceGrassed = 20;
	
	public :
		//CTOR : Memaanggil randomGrassed()
		Land();
		
		//SELECTOR
		void setGrass(bool input);      // setter boolean grassed
		bool getGrass() const;          // getter boolean grassed
};


#endif //ENGISFARM_LAND_HPP
