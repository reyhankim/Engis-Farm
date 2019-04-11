#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <stdlib.h>
#include "Node.hpp"

using namespace std;

// Class LinkedList adalah blueprint dari objek yang dapat menampung data dengan representasi LinkedList
template <class T>
class LinkedList{

	public :
		Node<T>* head = NULL;
		int Count;

		LinkedList();

		LinkedList(const LinkedList& L);

		~LinkedList();

		//LinkedList& operator=(const LinkedList& L);

		bool isEmpty(){				// Mengembalikan True jika LinkedList kosong
			return head == NULL;
		}

		int find(T element);		// Mengembalikan indeks di mana elemen ditemukan, -1 jika tidak ada

		void add(T element);		// Menambahkan elemen sebagai elemen paling akhir

		void remove(T element);		// Membuang elemen dari linked list

		T get(int index);			// Mengembalikan elemen pada indeks
};

template<class T>
LinkedList<T>::LinkedList(){
	head = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L){
	Node<T>* iter = L.head;
    while(iter != NULL) {
    	add(iter->info);
    }
}

template<class T>
LinkedList<T>::~LinkedList(){
	while(!isEmpty()){
		Node<T>* iter = head;
		head = head->next;
		delete iter;
	}
}
/*
template<class T>
LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>& L){
	if(&L != this) {
        	
        Node<T>* iter = head;
        while(iter->next != NULL) {
        	head = head->next;
        	delete iter;
            iter = head;
        }
        		
        iter = L.head;
        while(iter != NULL) {
            this->add(iter->info);
			iter = iter->next;
        }
    }
    return *this;
}*/

template<class T>
T LinkedList<T>::get(int index){
	if(!isEmpty()){
		Node<T>* iter = head;
		int currentIndex = 0;

		while (iter->next != NULL && currentIndex < index)
		{
			iter = iter->next;
			currentIndex++;
		}

		if (currentIndex == index)
		{
			return iter->info;
		}
		else
		{
			return NULL;
		}
	}
	else{
		return NULL;
	}
}

template<class T>
void LinkedList<T>::remove(T element){
	if(!isEmpty()){
		Node<T>* iter = head;
		Node<T>* prev = NULL;
		bool found;
		while(!found && iter->next != NULL){
			if(iter->info == element){
				found = true;
			}
			else{
				prev = iter;
				iter = iter->next;
			}
		}

		if(iter->info == element){
			found = true;
		}

		if(found){
			if(prev != NULL){
				prev->next = iter->next;
			}

			delete iter;
		}
	}
}

template<class T>
void LinkedList<T>::add(T element){
	Node<T>* input = new Node<T>();	
	input->info = element;
			
	if(!isEmpty()){
		Node<T>* iter = head;
		while(iter->next != NULL){
			iter = iter->next;
		}

		iter->next = input;
	}
	else{
		head = input;
	}
}

template<class T>
int LinkedList<T>::find(T element){
	int i = 0;
	bool found = false;
	Node<T>* iter = head;
	while(!found && iter != NULL){
		if(iter->info == element){
			found = true;
		}
		else{
			i++;
			iter = iter->next;
		}
	}

	if(found){
		return i;
	}
	else{
		return -1;
	}
}

#endif
