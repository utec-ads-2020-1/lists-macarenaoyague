#ifndef LIST_H
#define LIST_H

#include "node.h"

// TODO: Implement all methods
template <typename T>
class List {
    protected:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

    public:
        List() : head(nullptr), tail(nullptr), nodes(0) {};
        ~List();

        virtual T front() = 0;
        virtual T back() = 0;
        virtual void push_front(T element) = 0; //chequear forward  y linked para añadir la segunda
        virtual void push_back(T element) = 0;
        virtual void pop_front() = 0; //añadir si es que solo hay 1 elemento ----implement popTheOnlyNode
        virtual void pop_back() = 0; //añadit si es que solo hay 1 elemento
        virtual T operator[](int) = 0;
        virtual bool empty() = 0;
        virtual int size() = 0;
        virtual void clear() = 0;
        virtual void sort() = 0;
        virtual void reverse() = 0;
        virtual string name() = 0;

        virtual void addFirst(T element) = 0;
        virtual Node<T>* searchNode(int position) = 0;
};

template<typename T>
List<T>::~List() {
    delete head;
    delete tail;
}

#endif