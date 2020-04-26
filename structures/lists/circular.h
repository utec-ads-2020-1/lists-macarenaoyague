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
    T operator[](int position);
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

    void merge(CircularLinkedList<T>& list2);
};

template<typename T>
T CircularLinkedList<T>::front() {
    if (!empty())
        return this->head->data;
    throw std::out_of_range ("Empty list");
}

template<typename T>
T CircularLinkedList<T>::back() {
    if (!empty())
        return this->tail->data;
    throw std::out_of_range ("Empty list");
}

template<typename T>
void CircularLinkedList<T>::push_front(T element) {
    if (empty())
    {
        addFirst(element);
    }
    else
    {
        auto temporal = new Node<T>;
        temporal->data = element;
        temporal->next = this->head;
        temporal->prev = this->tail;
        this->tail->next = temporal;
        this->head->prev = temporal;
        this->head = temporal;
    }
    this->nodes++;
}

template<typename T>
void CircularLinkedList<T>::push_back(T element) {
    if (empty())
        addFirst(element);
    else
    {
        auto temporal = new Node<T>;
        temporal->data = element;
        temporal->prev = this->tail;
        temporal->next = this->head;
        this->tail->next = temporal;
        this->head->prev = temporal;
        this->tail = temporal;
    }
    this->nodes++;
}

template<typename T>
void CircularLinkedList<T>::pop_front() {
    auto temporal = this->head;
    if(size() == 1)
    {
        delete temporal;
        this->head = nullptr;
        this->tail = nullptr;
        this->nodes--;
    }
    else if (size()>1)
    {
        this->head = this->head->next;
        this->head->prev = this->tail;
        this->tail->next = this->head;
        delete temporal;
        this->nodes--;
    }
}

template<typename T>
void CircularLinkedList<T>::pop_back() {
    auto temporal = this->tail;
    if(size() == 1)
    {
        delete temporal;
        this->head = nullptr;
        this->tail = nullptr;
        this->nodes--;
    }
    if (size()>1)
    {
        this->tail = this->tail->prev;
        this->tail->next = this->head;
        this->head->prev = this->tail;
        delete temporal;
        this->nodes--;
    }
}

template<typename T>
T CircularLinkedList<T>::operator[](int position) {
    return searchNode(position)->data;
}

template<typename T>
bool CircularLinkedList<T>::empty() {
    return this->head == nullptr;
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
    T tempSecondHalf;
    for (int i = 0; i<size()/2; i++)
    {
        tempSecondHalf = searchNode(this->nodes -1 -i)->data;
        searchNode(this->nodes -1 -i)->data = searchNode(i)->data;
        searchNode(i)->data = tempSecondHalf;
    }
}

template<typename T>
void CircularLinkedList<T>::addFirst(T element) {
    auto temp = new Node <T>;
    this->head = temp;
    this->tail = temp;
    this->head->data = element;
    this->head->next = temp;
    this->head->prev = temp;
}

template<typename T>
Node<T> *CircularLinkedList<T>::searchNode(int position) {
    Node<T> * returnNode;
    if (position > this->nodes - 1 or position < 0)
    {
        throw std::out_of_range ("Error in range");
    }
    else
    {
        if (position < size()/2)
        {
            returnNode = this->head;
            for (int i = 1; i<=position; i++)
                returnNode = returnNode->next;
            return returnNode;
        }
        else
        {
            returnNode = this->tail;
            for (int i = size()-1; i>position; i--)
                returnNode = returnNode->prev;
            return returnNode;
        }
    }
}

template<typename T>
void CircularLinkedList<T>::merge(CircularLinkedList<T> &list2) {
    if (!list2.empty())
    {
        if (!empty())
        {
            //
            this->tail->next = list2.head;
            list2.head->prev = this->tail;
            this->head->prev = list2.tail;
            list2.tail->next = this->head;
            this->tail = list2.tail;
        }
        else
        {
            this->head = list2.head;
            this->tail = list2.tail;
        }
        this->nodes += list2.nodes;
        list2.nodes = 0;
        list2.head = nullptr;
        list2.tail = nullptr;
    }
}

template<typename T>
BidirectionalIterator<T> CircularLinkedList<T>::begin() {
    return BidirectionalIterator<T>(this->head);
}

template<typename T>
BidirectionalIterator<T> CircularLinkedList<T>::end() {
    auto *temp = new Node<T>;
    temp->next = nullptr;
    temp->prev =this->tail;
    return BidirectionalIterator<T>(temp);
}
#endif