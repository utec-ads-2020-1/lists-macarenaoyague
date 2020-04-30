#ifndef STACK_H
#define STACK_H

#include <stdexcept>

using namespace std;

#define MAX 1000 

template <typename T>
class stack {
    T* data;
    int top;
    int capacity;
    void duplicateCapacity();

public:
    stack(int size = MAX);

    ~stack(); //

    void push(T data);

    void pop();
    T peak();

    int size();
    bool empty();

};

template<typename T>
stack<T>::stack(int size) {
    capacity = size;
    data = new T [capacity];
    top = 0;
}

template<typename T>
void stack<T>::push(T data) {
    if (top == capacity-1)
        duplicateCapacity();
    this->data[top] = data;
    top++;
}

template<typename T>
void stack<T>::pop() {
    if (top != 0)
        top--;
}

template<typename T>
T stack<T>::peak() {
    if (top-1 >= 0)
        return this->data[top-1];
    throw std::out_of_range ("Empty stack");
}

template<typename T>
int stack<T>::size() {
    return top;
}

template<typename T>
bool stack<T>::empty() {
    return size() == 0;
}

template<typename T>
void stack<T>::duplicateCapacity(){
    capacity *= 2;
    T *temp = new T [capacity];
    for (int i = 0; i<capacity/2; i++)
        temp [i] = this->data[i];
    delete data;
    this->data = temp;
}

template<typename T>
stack<T>::~stack() {
    delete this->data; // []
}

#endif