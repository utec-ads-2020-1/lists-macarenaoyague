#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
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
    return BidirectionalIterator<T>(iterator.current);
}

template<typename T>
bool BidirectionalIterator<T>::operator!=(BidirectionalIterator<T> iterator) {
    return current!=iterator.current;
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator++() {
    if (current == nullptr)
        throw std::out_of_range ("Pointing to null. There is no next iterator.");
    return BidirectionalIterator<T>(current->next);
}

template<typename T>
BidirectionalIterator<T> BidirectionalIterator<T>::operator--() {

    return BidirectionalIterator<T>();
}

template<typename T>
T BidirectionalIterator<T>::operator*() {
    return nullptr;
}

#endif