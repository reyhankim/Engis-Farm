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
	public :
		Mixer(int axis, int ordinat);

		//Render
		char render() const override;
		
		//METHOD
		template <typename U, typename V>
		SideProduct* mix(U bahan1, V bahan2);
};
#endif //ENGISFARM_MIXER_HPP
