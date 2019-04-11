//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 11/03/2019

#ifndef ENGISFARM_PLAYER_HPP
#define ENGISFARM_PLAYER_HPP


#include "MovingObject.hpp"
#include "LinkedList.hpp"
#include "Product.hpp"

// Class player menyimpan data-data seperti gold, currentWater, dan player facing
// serta memiliki method untuk player berinteraksi dengan farm-nya
class Player : public MovingObject {
    // Data member:
private:
    int maxWater = 5; //kapasitas maksimum air yang dapat dibawa

    int gold; //uang yang dimiliki player
    int currentWater;

    int facing; //1 : facing up, 2 : facing down, 3 : facing right, 4 : facing left
	LinkedList<Product*> productInventory;  // list of pointer to Product

public:
	//CTOR
	Player();

	Player(int x, int y);

	//DTOR
	~Player();

	//Render
	char render() const override;

	// mengembalikan true jika productInventory kosong / memiliki 0 elemen
	bool isInventoryEmpty();
	// menambahkan Product ke inventory
	void addToInventory(Product* element);
	// menghapus Product dari inventory
	void removeFromInventory(Product* element);

	// getter
	int getGold() const;
	int getFacing() const;
	int getCurrentWater() const;
	Product* getProductFromInventory(int index);
	//setter
	void setGold(int amount);
	void setFacing(int direction);
	void setCurrentWater(int water);
};

#endif //ENGISFARM_PLAYER_HPP
