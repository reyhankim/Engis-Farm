//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 16/03/2019

#ifndef ENGISFARM_FACILITY_HPP
#define ENGISFARM_FACILITY_HPP


#include "Cell.hpp"

class Facility : public Renderable {
	public :
		bool isWalkable() const {
			return false;
		}	
};


#endif //ENGISFARM_FACILITY_HPP
