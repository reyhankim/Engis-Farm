
#include "../include/SideProduct.hpp"

// Class SideProduct adalah blueprint dari Product yang dihasilkan dari gabungan FarmProduct

//Ctor
SideProduct::SideProduct(){
    Product::setHarga();
}

SideProduct::~SideProduct() {}
