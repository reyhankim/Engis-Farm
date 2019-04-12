//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 16/03/2019

#ifndef ENGISFARM_FACILITY_HPP
#define ENGISFARM_FACILITY_HPP


#include "Cell.hpp"

// Class Land adalah blueprint dari objek turunan "Cell" yang tidak dapat ditempati oleh Animal atau Player
class Facility : public Cell {
public:
    Facility(int x, int y);
    
    virtual ~Facility() = default; // virtual DTOR
};


#endif //ENGISFARM_FACILITY_HPP
