//
// Created by reyha on 27/02/2019.
// Last edited by SiR on 11/03/2019

#ifndef ENGISFARM_PLAYER_HPP
#define ENGISFARM_PLAYER_HPP


#include "Renderable.hpp"
#include "Product.hpp"
#include "LinkedList.hpp"
#include "Scene.hpp"

// Class player menyimpan data-data seperti gold, currentWater, dan player facing
// serta memiliki method untuk player berinteraksi dengan farm-nya
class Player : public Renderable {
    // Data member:
private:
    int maxWater = 5; //kapasitas maksimum air yang dapat dibawa

    int gold; //uang yang dimiliki player
    int currentWater;

    int facing; //1 : facing up, 2 : facing down, 3 : facing right, 4 : facing left
	LinkedList<Product*> productInventory = LinkedList<Product*>();  // list of pointer to Product

public:
	friend class Scene;
	//CTOR
	Player();

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
	// mengembalikan objek Renderable yang berada di depan player
	Renderable* getInFront(Scene s);

	// getter
	int getGold() const;
	int getFacing() const;
	int getCurrentWater() const;
	Product* getProductFromInventory(int index);
	//setter
	void setGold(int amount);
	void setCurrentWater(int water);

    // method untuk mengubah posisi player ke arah tertentu.
	// player mengubah orientasi tanpa bergerak jika collision dengan
	// obyek yang tidak dapat dilewati (isWalkable()==false).
    void move(int direction, Scene s);

	// menerima objek Renderable, jika merupakan FarmAnimal mencetak hasil dari fungsi sound()
    template<typename T>
	void talk(T* x);

	// menerima objek Renderable dan melakukan interaksi berdasarkan jenis kelas turunannya
    template<typename T>
	void interact(T* x);

	// menerima objek Renderable, jika merupakan FarmAnimal membunuhnya dengan cara memanggil
	// dekostruktornya.
	template<typename T>
    void kill(T* x);			// Marked by Kim: Kill untuk masing-masing hewan menghasilkan product berbeda, apa mending template aja?

	// menyiram (mengurangi air) petak yang ditempati player sehingga tumpuh rumput (grass)
	template<typename T>
    void grow(T* r);
};

#endif //ENGISFARM_PLAYER_HPP
