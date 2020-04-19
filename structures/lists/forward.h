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
        void merge(ForwardList<T>&);
};

template<typename T>
T ForwardList<T>::front() {
    if (!empty())
        return this->head->data;
    //throw exception
}

template<typename T>
T ForwardList<T>::back() {
    if (!empty())
        return this->tail->data;
    //throw exception
}

template<typename T>
void ForwardList<T>::push_front(T element) {
    if (empty())
    {
        addFirst(element);
    }
    else
    {
        Node<T>* temporal = this->head;
        this->head = new Node<T>;
        this->head->data = element;
        this->head->next = temporal;
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
        Node<T>* temporal = this->tail;
        this->tail = new Node<T>;
        this->tail->data = element;
        this->tail->next = nullptr;
        temporal->next = this->tail;
    }
    this->nodes++;

}

template<typename T>
void ForwardList<T>::pop_front() {
    if (empty())
    {
        //error
    }
    else
    {
        Node<T>* temporal = this->head;
        this->head = this->head->next;
        temporal->killSelf();
        delete temporal;
        this->nodes--;
    }
}

template<typename T>
void ForwardList<T>::pop_back() {
    if (empty())
    {
        //error
    }
    else
    {
        Node<T>* temporal = this->tail;
        this->tail = searchNode(this->nodes-2);
        this->tail->next = nullptr;
        temporal->killSelf();
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
    //arreglar?
    if (this->head == nullptr)
        return true;
    else
        return false;
}

template<typename T>
int ForwardList<T>::size() {
    return this->nodes;
}

template<typename T>
void ForwardList<T>::clear() {
    for (int i = 0; i<this->nodes; i++)
        pop_front();
}

template<typename T>
void ForwardList<T>::sort() {
    //
}

template<typename T>
void ForwardList<T>::reverse() {
    Node<T> *current = this->tail;
    for (int i = this->nodes-1; i>0; i++)
    {
        current->next = searchNode(i-1);
        current = current->next;
    }
    current->next = nullptr;
    current = this->head;
    this->head = this->tail;
    this->tail = current;
}

template<typename T>
void ForwardList<T>::addFirst(T element) {
    this->head = new Node <T>;
    this->tail = this->head;
    this->head->data = element;
    this->head->next = nullptr;
}

template<typename T>
Node<T> *ForwardList<T>::searchNode(int position) {
    Node<T> * returnNode;
    if (position > this->nodes - 1 or position < 0)
    {
        //error
    }
    //if is tail
    else
    {
        returnNode = this->head;
        for (int i = 1; i<=position; i++)
            returnNode = returnNode->next;
        return returnNode;
    }
}

template<typename T>
void ForwardList<T>::merge(ForwardList<T> &) {
    //
}

#endif