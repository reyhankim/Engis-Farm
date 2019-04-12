//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_PRODUCT_HPP
#define ENGISFARM_PRODUCT_HPP


// Class Product adalah blueprint dari seluruh produk yang dapat disimpan dan dijual
class Product {
protected:
    int harga;              // Menyimpan harga dari Product

public:
    virtual ~Product() = default;     // virtual DTOR

    int getHarga() const;   // Getter harga

    void setHarga();        // Setter harga
};


#endif //ENGISFARM_PRODUCT_HPP
