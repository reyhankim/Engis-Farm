//
// Created by reyha on 27/02/2019.
//

#ifndef ENGISFARM_FARMPRODUCT_HPP
#define ENGISFARM_FARMPRODUCT_HPP


class FarmProduct {
    protected:
        int harga;
        void setHarga();

    public:
        //ctor
        FarmProduct();

        //selector
        int getHarga();
};


#endif //ENGISFARM_FARMPRODUCT_HPP
