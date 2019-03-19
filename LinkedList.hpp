#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <vector>
using namespace std;

template <class T>
class LinkedList{
	private :
		vector<T> list;
	
	public :
		LinkedList();
		
		bool isEmpty();
		int find(T element);
		void add(T element);
		void remove(T element);
		T get(int index);
		
};

#endif
