//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_SIDEPRODUCT_HPP
#define ENGISFARM_SIDEPRODUCT_HPP


#include "Product.hpp"

// Class SideProduct adalah blueprint dari Product yang dihasilkan dari gabungan FarmProduct
class SideProduct : public Product {

public:
    //Ctor
    SideProduct();
    // virtual DTOR
    virtual ~SideProduct() = default;
};


#endif //ENGISFARM_SIDEPRODUCT_HPP
