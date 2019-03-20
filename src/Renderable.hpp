//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 16/03/2019

#ifndef ENGISFARM_RENDERABLE_HPP
#define ENGISFARM_RENDERABLE_HPP

// Class Renderable adalah blueprint dari objek yang di-inherit oleh objek-objek yang memiliki posisi
class Renderable {
	public :
        Renderable();                          // Default ctor
	    Renderable(int x, int y);              // User defined ctor : menentukan koordinat x dan y dalam ctor
		virtual char render() const = 0;		// pure virtual dari method render
		void setX(int x);                      // setter X
		void setY(int y);                      // setter Y
		int getX() const;                      // getter X
		int getY() const;                      // getter Y
	
	private :
		int x;			// posisi secara horizontal
		int y;			// posisi secara vertikal
};


#endif //ENGISFARM_RENDERABLE_HPP
