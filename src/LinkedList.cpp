#include "../include/LinkedList.hpp"

template<class T>
LinkedList<T>::LinkedList(){
	head = NULL;
	Count = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& L){
	Node* iter = L.head;
    while(iter != NULL) {
    	add(iter->info);
		iter = iter->next;
    }

	Count = L.Count;
}

template<class T>
LinkedList<T>::~LinkedList(){
	while(!isEmpty()){
		Node* iter = head;
		head = head->next;
		delete iter;
	}
}

template<class T>
LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>& L){
	if(&L != this) {
        	
        Node* iter = head;
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

	Count = L.Count;
    return *this;
}

template<class T>
T LinkedList<T>::get(int index){
	if(!isEmpty()){
		Node* iter = head;
		T element;
		while(iter->next != NULL && index >=0){
			if(index == 0){
			element = iter->info;
			}
			else{
				iter = iter->next;
				index--;
			}
		}

		if(index > 0){
			return NULL;
		}
		else{
			return element;
		}
	}
	else{
		return NULL;
	}
}

template<class T>
void LinkedList<T>::remove(T element){
	if(!isEmpty()){
		Node* iter = head;
		Node* prev = NULL;
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

		Count--;
	}
}

template<class T>
void LinkedList<T>::add(T element){
	Node* input = new Node();	
	input->info = element;
			
	if(!isEmpty()){
		Node* iter = head;
		while(iter->next != NULL){
			iter = iter->next;
		}

		iter->next = input;
	}
	else{
		head = input;
	}

	Count++;
}

template<class T>
int LinkedList<T>::find(T element){
	int i = 0;
	bool found = false;
	Node* iter = head;
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