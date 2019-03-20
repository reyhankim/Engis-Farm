#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

using namespace std;

// Class LinkedList adalah blueprint dari objek yang dapat menampung data dengan representasi LinkedList
template <class T>
class LinkedList{
	private :
		struct Node{
			T info;					// Menampung informasi yang disimpan pada LinkedList
			Node *next, *prev;		// Pointer
		};
		
		Node *list;					// Untaian node yang membentuk linked list
	
	public :
		LinkedList();				// Constructor
		
		bool isEmpty();				// Mengembalikan True jika LinkedList kosong
		int find(T element);		// Mengembalikan indeks di mana elemen ditemukan, -1 jika tidak ada
		void add(T element);		// Menambahkan elemen sebagai elemen paling akhir
		void remove(T element);		// Membuang elemen dari linked list
		T get(int index);			// Mengembalikan elemen pada indeks
		
};

#endif
