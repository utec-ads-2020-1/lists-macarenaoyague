#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
public:
    ForwardList() : List<T>() {}

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

    ForwardIterator<T> begin();
    ForwardIterator<T> end();

    string name() {
        return "Forward List";
    }

    void merge(ForwardList<T>& list2);
};

template<typename T>
T ForwardList<T>::front() {
    if (!empty())
        return this->head->data;
    throw std::out_of_range ("Empty list");
}

template<typename T>
T ForwardList<T>::back() {
    if (!empty())
        return this->tail->data;
    throw std::out_of_range ("Empty list");
}

template<typename T>
void ForwardList<T>::push_front(T element) {
    if (empty())
    {
        addFirst(element);
    }
    else
    {
        auto temporal = new Node<T>;
        temporal->data = element;
        temporal->next = this->head;
        this->head = temporal;
    }
    this->nodes++;
}

template<typename T>
void ForwardList<T>::push_back(T element) {
    if (empty())
    {
        addFirst(element);
    }
    else
    {
        auto temporal = new Node<T>;
        temporal->data = element;
        temporal->next = nullptr;
        this->tail->next = temporal;
        this->tail = temporal;
    }
    this->nodes++;
}

template<typename T>
void ForwardList<T>::pop_front() {
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
        delete temporal;
        this->nodes--;
    }
}

template<typename T>
void ForwardList<T>::pop_back() {
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
        this->tail = searchNode(this->nodes-2); //cambiar x iterator :) pero esta bien
        this->tail->next = nullptr;
        delete temporal;
        this->nodes--;
    }
}

template<typename T>
T ForwardList<T>::operator[](int position) {
    return searchNode(position)->data;
}

template<typename T>
bool ForwardList<T>::empty() {
    return this->head == nullptr;
}

template<typename T>
int ForwardList<T>::size() {
    return this->nodes;
}

template<typename T>
void ForwardList<T>::clear() {
    auto current = this->head;


}

template<typename T>
void ForwardList<T>::sort() {
    //
}

template<typename T>
void ForwardList<T>::reverse() {
    T tempSecondHalf;
    for (int i = 0; i<size()/2; i++)
    {
        tempSecondHalf = searchNode(this->nodes -1 -i)->data;
        searchNode(this->nodes -1 -i)->data = searchNode(i)->data;
        searchNode(i)->data = tempSecondHalf;
    }
}

template<typename T>
void ForwardList<T>::addFirst(T element) {
    auto temp = new Node <T>;
    temp->data = element;
    temp->next = nullptr;
    this->head = temp;
    this->tail = temp;
}

template<typename T>
Node<T> *ForwardList<T>::searchNode(int position) {
    Node<T> * returnNode;
    if (position > this->nodes - 1 or position < 0)
    {
        throw std::out_of_range ("Error in range");
    }
    else
    {
        if (position == size()-1)
            return this->tail;
        returnNode = this->head;
        for (int i = 1; i<=position; i++)
            returnNode = returnNode->next;
        return returnNode;
    }
}

template<typename T>
void ForwardList<T>::merge(ForwardList<T> &list2) {
    //ordenar ambos
    if (!list2.empty())
    {
        if (!empty())
        {
            this->tail->next = list2.head;
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
ForwardIterator<T> ForwardList<T>::begin() {
    return ForwardIterator<T>(this->head);
}

template<typename T>
ForwardIterator<T> ForwardList<T>::end() {
    return ForwardIterator<T>(this->tail);
}


#endif