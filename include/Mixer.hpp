//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_MIXER_HPP
#define ENGISFARM_MIXER_HPP


#include "Product.hpp"
#include "SideProduct.hpp"
#include "FarmProduct.hpp"
#include "Facility.hpp"

// Class Mixer adalah blueprint dari objek turunan "Facility" yang dapat menghasilkan SideProduct dari gabungan FarmProduct
class Mixer : public Facility {
	private :
		static int const row = 3;
		Product **listSideProduct;
		//struktur array
		// | Side Product | Farm Product 1 | Farm Product 2 |
	
	public :
		//CTOR
		Mixer();
		
		//DTOR
		~Mixer();
		
		//Render
		char render() const override;
		
		//METHOD
		SideProduct mix(FarmProduct bahan1, FarmProduct bahan2);
};
#endif //ENGISFARM_MIXER_HPP
