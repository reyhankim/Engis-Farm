#include "../include/Counter.hpp"

template <typename T>
int Counter<T>::objects_created( 0 );

template <typename T>
int Counter<T>::objects_alive( 0 );

// CTOR
template <typename T>
Counter<T>::Counter(){
    objects_created++;
    objects_alive++;
}
// DTOR
template <typename T>
Counter<T>::~Counter() {
    --objects_alive;
}