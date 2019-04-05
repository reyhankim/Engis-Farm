#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <algorithm>
#include <stdlib.h>

using namespace std;

// Class LinkedList adalah blueprint dari objek yang dapat menampung data dengan representasi LinkedList
template <class T>
class LinkedList{

	private:
    	class Node {
    		public:
        		T info;
       			Node *next;

        		// CTOR DEF
        		Node() = default;

        		// CCTOR
        		Node(const T& input){
					this->info = input;
					this->next = NULL;
				}

    	};

	public :
		Node* head = NULL;
		int Count;

		LinkedList();

		LinkedList(const LinkedList& L);

		~LinkedList();

		LinkedList& operator=(const LinkedList& L);

		bool isEmpty(){				// Mengembalikan True jika LinkedList kosong
			return head == NULL;
		}

		int find(T element);		// Mengembalikan indeks di mana elemen ditemukan, -1 jika tidak ada

		void add(T element);		// Menambahkan elemen sebagai elemen paling akhir

		void remove(T element);		// Membuang elemen dari linked list

		T get(int index);			// Mengembalikan elemen pada indeks
};

#endif
