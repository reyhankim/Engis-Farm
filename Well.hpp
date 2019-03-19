//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 11/03/2019

#ifndef ENGISFARM_WELL_HPP
#define ENGISFARM_WELL_HPP

#include "Facility.hpp"

class Well : public Facility {
	public :
		char render() const override;
};


#endif //ENGISFARM_WELL_HPP
