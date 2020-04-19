#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

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
            return "Circular Linked List";
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
        void merge(CircularLinkedList<T>&);
};

template<typename T>
T CircularLinkedList<T>::front() {
    if (empty())
    {
        //error
    }
    else
        return this->head->data;
}

template<typename T>
T CircularLinkedList<T>::back() {
    if (empty())
    {
        //error
    }
    else
        return this->tail->data;
}

template<typename T>
void CircularLinkedList<T>::push_front(T element) {
    if(empty())
        addFirst(element);
    else
    {
        Node<T> *temp = this->head;
        this->head = new Node<T>;
        this->head->data = element;
        this->head->next = temp;
        this->head->prev = temp->prev;
        temp->prev = this->head;
        this->tail->next = this->head;
    }
    this->nodes++;
}

template<typename T>
void CircularLinkedList<T>::push_back(T element) {
    if (empty())
        addFirst(element);
    else
    {
        Node<T> *temp = this->tail;
        this->tail = new Node<T>;
        this->tail->data = element;
        this->tail->prev = temp;
        this->tail->next = temp->next;
        temp->next = this->tail;
        this->head->prev = this->tail;
    }
    this->nodes++;
}

template<typename T>
void CircularLinkedList<T>::pop_front() {
    if (empty())
    {
        //error
    }
    else
    {
        Node<T> *temp = this->head;
        this->head = this->head->next;
        this->head->prev = temp->prev;
        this->tail->next = this->head;
        temp->killSelf();
        delete temp;
        this->nodes--;
    }

}

template<typename T>
void CircularLinkedList<T>::pop_back() {
    if (empty())
    {
        //
    }
    else
    {
        Node<T> *temp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = temp->next;
        this->head->prev = this->tail;
        temp->killSelf();
        delete temp;
        this->nodes--;
    }

}

template<typename T>
T CircularLinkedList<T>::operator[](int) {
    return nullptr;
}

template<typename T>
bool CircularLinkedList<T>::empty() {
    //arreglar?
    if (this->head == nullptr)
        return true;
    else
        return false;
}

template<typename T>
int CircularLinkedList<T>::size() {
    return this->nodes;
}

template<typename T>
void CircularLinkedList<T>::clear() {

}

template<typename T>
void CircularLinkedList<T>::sort() {

}

template<typename T>
void CircularLinkedList<T>::reverse() {

}

template<typename T>
void CircularLinkedList<T>::addFirst(T element) {
    this->head = new Node<T>;
    this->head->data = element;
    this->tail = this->head;
    this->head->next = this->head; //apuntarse a sí misma???? si no, chequear push
    this->head->prev = this->head;
}

template<typename T>
Node<T> *CircularLinkedList<T>::searchNode(int position) {
    //
}

#endif