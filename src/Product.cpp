//
// Created by novendraw on 4/4/19.
//

#include <cstdlib>
#include "../include/Product.hpp"

// Class Product adalah blueprint dari seluruh produk yang dapat disimpan dan dijual

    int Product::getHarga() const{
        return harga;
    }   // Getter harga

    void Product::setHarga(){
        harga = rand() % 1000000 + 1; // range harga dari 1 sampai 1000000
    }        // Setter harga

