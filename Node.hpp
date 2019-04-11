#ifndef NODE_HPP
#define NODE_HPP

#include <stdlib.h>

template <class T>
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

#endif