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
        return "Linked List";
    }

    void merge(LinkedList<T> &list2);
};

template<typename T>
T LinkedList<T>::front() {
    if (!empty())
        return this->head->data;
    throw std::out_of_range ("Empty list");
}

template<typename T>
T LinkedList<T>::back() {
    if (!empty())
        return this->tail->data;
    throw std::out_of_range ("Empty list");
}

template<typename T>
void LinkedList<T>::push_front(T element) {
    if (empty())
    {
        addFirst(element);
    }
    else
    {
        auto temporal = new Node<T>;
        temporal->data = element;
        temporal->next = this->head;
        temporal->prev = nullptr;
        this->head->prev = temporal;
        this->head = temporal;
    }
    this->nodes++;
}

template<typename T>
void LinkedList<T>::push_back(T element) {
    if (empty())
        addFirst(element);
    else
    {
        auto temporal = new Node<T>;
        temporal->data = element;
        temporal->next = nullptr;
        temporal->prev = this->tail;
        this->tail->next = temporal;
        this-> tail = temporal;
    }
    this->nodes++;
}

template<typename T>
void LinkedList<T>::pop_front() {
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
        this->head->prev = nullptr;
        delete temporal;
        this->nodes--;
    }
}

template<typename T>
void LinkedList<T>::pop_back() {
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
        this->tail->next = nullptr;
        delete temporal;
        this->nodes--;
    }
}

template<typename T>
T LinkedList<T>::operator[](int position) {
    return searchNode(position)->data;
}

template<typename T>
bool LinkedList<T>::empty() {
    return this->head == nullptr;
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
    int N = size();
    int size = N;
    bool somethingChange;
    T temp;
    while (N != 1)
    {
        N = N/2;
        do{
            somethingChange = false;
            for (int i = 0; i<size-N; i++)
            {
                if (searchNode(i)->data > searchNode(i+N)->data)
                {
                    temp = searchNode(i)->data;
                    searchNode(i)->data = searchNode(i+N)->data;
                    searchNode(i+N)->data = temp;
                    if (!somethingChange)
                        somethingChange = true;
                }
            }
        }while (somethingChange);
    }
}

template<typename T>
void LinkedList<T>::reverse() {
    T tempSecondHalf;
    for (int i = 0; i<size()/2; i++)
    {
        tempSecondHalf = searchNode(this->nodes -1 -i)->data;
        searchNode(this->nodes -1 -i)->data = searchNode(i)->data;
        searchNode(i)->data = tempSecondHalf;
    }
}

template<typename T>
void LinkedList<T>::addFirst(T element) {
    auto temp = new Node <T>;
    this->head = temp;
    this->tail = temp;
    this->head->data = element;
    this->head->next = nullptr;
    this->head->prev = nullptr;
}

template<typename T>
Node<T> *LinkedList<T>::searchNode(int position) {
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
void LinkedList<T>::merge(LinkedList<T> &list2) {
    if (!list2.empty())
    {
        if (!empty())
        {
            this->tail->next = list2.head;
            list2.head->prev = this->tail;
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
    sort();
}

template<typename T>
BidirectionalIterator<T> LinkedList<T>::begin() {
    return BidirectionalIterator<T>(this->head);
}

template<typename T>
BidirectionalIterator<T> LinkedList<T>::end() {
    auto *temp = new Node<T>;
    temp->next = nullptr;
    temp->prev =this->tail;
    return BidirectionalIterator<T>(temp);
}
#endif