//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 11/03/2019

#ifndef ENGISFARM_PLAYER_HPP
#define ENGISFARM_PLAYER_HPP

#include "Renderable.hpp"
#include "Product.hpp"

#define NULL nil

class Player : public Renderable {
    // Data member:
private:
    const int maxWater; //kapasitas maksimum air yang dapat dibawa

    int gold; //uang yang dimiliki player
    int currentWater;

    int facing; //1 : facing up, 2 : facing down, 3 : facing right, 4 : facing left

    Product** productInventory; // array of pointer to Product

public:
	//CTOR
	Player();
	
	//DTOR
	~Player();
	
	//Render
	virtual char render();
	
	//method dasar (lupa namanya)
	int checkInFront(Product* element);
	bool isInventoryEmpty();
	void addToInventory(Product* element);
	void removeFromInventory(Product* element);
	
    // SELECTORS here
	int getGold() const;
	int getFacing() const;
	int getCurrentWater() const;
	Product* getProductFromInventory(int index) const;
	
	void setGold() const;
	void setCurrentWater(int water);
	
    // METHOD move here
	// setFacing akan diatur di method move
    void up();
    void down();
    void left();
    void right();

    void talk();

    void interact();

    void kill();

    void grow();

    void emptyBag();
};


#endif //ENGISFARM_PLAYER_HPP
