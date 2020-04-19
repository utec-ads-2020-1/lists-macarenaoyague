#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front();
        T back();
        void push_front(T element);
        void push_back(T element);
        void pop_front();
        void pop_back();
        T operator[](int);
        bool empty();
        int size();
        void clear();
        void sort();
        void reverse();

        void addFirst(T element);
        Node<T>* searchNode(int position);

        BidirectionalIterator<T> begin();
	    BidirectionalIterator<T> end();

        string name() {
            return "Linked List";
        }

        /**
         * Merges x into the list by transferring all of its elements at their respective 
         * ordered positions into the container (both containers shall already be ordered).
         * 
         * This effectively removes all the elements in x (which becomes empty), and inserts 
         * them into their ordered position within container (which expands in size by the number 
         * of elements transferred). The operation is performed without constructing nor destroying
         * any element: they are transferred, no matter whether x is an lvalue or an rvalue, 
         * or whether the value_type supports move-construction or not.
        */
        void merge(LinkedList<T>&);
};

template<typename T>
T LinkedList<T>::front() {
    if (!empty())
        return this->head->data;
    //exception
}

template<typename T>
T LinkedList<T>::back() {
    if (!empty())
        return this->tail->data;
    //exception
}

template<typename T>
void LinkedList<T>::push_front(T element) {
    if (empty())
        addFirst(element);
    else
    {
        Node<T> *temp = this->head;
        this->head = new Node<T>;
        this->head->data = element;
        this->head->next = temp;
        this->head->prev = nullptr;
        temp->prev = this->head;
    }
    this->nodes++;
}

template<typename T>
void LinkedList<T>::push_back(T element) {
    if (empty())
        addFirst(element);
    else
    {
        Node<T> *temp = this->tail;
        this->tail = new Node<T>;
        this->tail->data = element;
        this->tail->prev = temp;
        this->tail->next = nullptr;
        temp->next = this->tail;
    }
    this->nodes++;
}

template<typename T>
void LinkedList<T>::pop_front() {
    if (empty())
    {
        //error
    }
    else
    {
        Node<T> *temp = this->head;
        this->head = this->head->next;
        this->head->prev = nullptr;
        temp->killSelf();
        delete temp;
        this->nodes--;
    }
}

template<typename T>
void LinkedList<T>::pop_back() {
    if (empty())
    {
        //error
    }
    else
    {
        Node<T> *temp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
        temp->killSelf();
        delete temp;
        this->nodes--;
    }
}

template<typename T>
T LinkedList<T>::operator[](int) {
    return nullptr;
}

template<typename T>
bool LinkedList<T>::empty() {
    //simplify
    if (this->head == nullptr)
        return true;
    else
        return false;
}

template<typename T>
int LinkedList<T>::size() {
    return this->nodes;
}

template<typename T>
void LinkedList<T>::clear() {

}

template<typename T>
void LinkedList<T>::sort() {
//
}

template<typename T>
void LinkedList<T>::reverse() {
//
}

template<typename T>
void LinkedList<T>::addFirst(T element) {
    this->head = new Node<T>;
    this->tail = this->head;
    this->head->data = element;
    this->head->next = nullptr;
    this->head->prev = nullptr;
}

template<typename T>
Node<T> *LinkedList<T>::searchNode(int position) {
    //
    return nullptr;
}

#endif