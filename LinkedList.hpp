#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

using namespace std;

template <class T>
class LinkedList{
	private :
		struct Node{
			T info;
			Node *next, *prev;
		};
		
		Node *list;
	
	public :
		LinkedList();
		
		bool isEmpty();
		int find(T element);
		void add(T element);
		void remove(T element);
		T get(int index);
		
};

#endif
