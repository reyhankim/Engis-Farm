//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 16/03/2019

#ifndef ENGISFARM_CELL_HPP
#define ENGISFARM_CELL_HPP

#include "Renderable.hpp"

// Untuk pengelompokan kelas dan akan diinherit oleh Land dan Facilities
class Cell : public Renderable {
    private:
        bool walkable;				// Boolean walkable = true untuk objek yang dapat ditempati oleh Player atau Animal
    public:
        Cell();                    // Initialize walkable menjadi True
        // getter untuk walkable
		bool isWalkable() const;
		void setWalkable();        // setter untuk walkable
};


#endif //ENGISFARM_CELL_HPP
