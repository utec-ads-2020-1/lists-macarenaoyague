#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"

template <typename T>
class BidirectionalIterator {
private:
    Node<T> *current;

public:
    BidirectionalIterator();
    BidirectionalIterator(Node<T>* node);

    BidirectionalIterator<T> operator=(BidirectionalIterator<T> iterator);

    bool operator!=(BidirectionalIterator<T> iterator);

    BidirectionalIterator<T> operator++();

    BidirectionalIterator<T> operator--();

    T operator*();
};

template<typename T>
BidirectionalIterator<T>::BidirectionalIterator() {
    current = nullptr;
}

template<typename T>
BidirectionalIterator<T>::BidirectionalIterator(Node<T> * node) {
    current = node;
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator=(BidirectionalIterator<T> iterator) {
    current=iterator.current;                //equals the iterator to another
    return BidirectionalIterator<T>(current);     //but the definition of this is to return a new iterator
    // Estás creando un nuevo iterador, con this retornas el mismo 
}

template<typename T>
bool BidirectionalIterator<T>::operator!=(BidirectionalIterator<T> iterator) {
    return current!=iterator.current;
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator++() {
    if (current == nullptr)
        throw std::out_of_range ("Pointing to null. There is no next iterator.");
    current=current->next;                     //advance one position
    return BidirectionalIterator<T>(current);       //but the definition of this is to return a new iterator
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator--() {
    if (current == nullptr)
        throw std::out_of_range ("Pointing to null. There is no next iterator.");
    current=current->prev;                     //advance one position
    return BidirectionalIterator<T>(current);       //but the definition of this is to return a new iterator

}

template<typename T>
T BidirectionalIterator<T>::operator*() {
    if (current == nullptr)
        throw std::out_of_range ("Pointing to null. There is no data.");
    return current->data;
}


#endif