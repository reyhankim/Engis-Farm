//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 16/03/2019

#ifndef ENGISFARM_RENDERABLE_HPP
#define ENGISFARM_RENDERABLE_HPP


class Renderable {
	public :
		virtual char render() const = 0;
	
	protected :
		int x;
		int y;
};


#endif //ENGISFARM_RENDERABLE_HPP
