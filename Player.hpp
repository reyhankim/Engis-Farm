//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 11/03/2019

#ifndef ENGISFARM_PLAYER_HPP
#define ENGISFARM_PLAYER_HPP

#include "Renderable.hpp"
#include "Product.hpp"

#define NULL nil

template <class T>
class Player : public Renderable {
    // Data member:
private:
    int currentWater;
    const int maxWater; //kapasitas maksimum air yang dapat dibawa
    Product *productInventory;
    int facing; //1 : facing up, 2 : facing down, 3 : facing right, 4 : facing left
    int gold; //uang yang dimiliki player

public:
	//CTOR
	Player();
	
	//DTOR
	~Player();
	
	//Render
	void render();
	
	//method dasar (lupa namanya)
	int find(T element);
	bool isEmpty();
	void addInventory(T element);
	void removeInventory(T element);
	T getInventory(int indeks);
	
    // SELECTORS here
	int getCurrentWater() const;
	Product getProductInventory(int i) const;
	int getFacing() const;
	int getGold() const;
	
	void setCurrentWater();
	void setProductInventory(int i, Product new_product);
	//setFacing akan diatur di method move
	void setGold() const;
	
    // METHOD move here
    void up();
    void down();
    void left();
    void right();

    // METHOD talk here
    void talk();

    // Other METHODS below
    void interact();
    void kill();
    void grow();
    void emptyBag();
};


#endif //ENGISFARM_PLAYER_HPP
