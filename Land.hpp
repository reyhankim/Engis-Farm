//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 15/03/2019

#ifndef ENGISFARM_LAND_HPP
#define ENGISFARM_LAND_HPP


#include "Cell.hpp"

class Land : public Cell {
	protected :
		bool grassed;
		// menentukan secara acak apakah Land akan berrumput (dipanggil oleh CTOR)
		void randomGrass();
	
	public :
		//CTOR
		Land();
		
		//SELECTOR
		void setGrass(bool input);
		bool getGrass() const;
};


#endif //ENGISFARM_LAND_HPP
