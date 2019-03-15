//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 16/03/2019

#ifndef ENGISFARM_CELL_HPP
#define ENGISFARM_CELL_HPP

#include "Renderable.hpp"

template <class T>
class Cell {
	private :
		Renderable **renderThing;
	
	public :
		//CTOR
		Cell();
		
		//DTOR
		~Cell();
		
		//SELECTOR
		void setCell(int x, int y, T element);
		T getCell(int x, int y);
};


#endif //ENGISFARM_CELL_HPP
