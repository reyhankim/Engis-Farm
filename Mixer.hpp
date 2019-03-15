//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_MIXER_HPP
#define ENGISFARM_MIXER_HPP


class Mixer {
	private :
		Product **listSideProduct;
		//struktur array
		// | Side Product | Farm Product 1 | Farm Product 2 |
	
	public :
		//CTOR
		Mixer();
		
		//DTOR
		~Mixer();
		
		//Render
		void render();
		
		//METHOD
		SideProduct mix(FarmProduct farmProduct, FarmProduct farmProduct);
};


#endif //ENGISFARM_MIXER_HPP
