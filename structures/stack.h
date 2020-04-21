#ifndef STACK_H
#define STACK_H

#include <stdexcept>

using namespace std;

#define MAX 1000 

// TODO: Implement all methods
template <typename T>
class stack {
	T* data;
	int top; //índice de último elemento insertado
	int capacity;

public:
	stack(int size = MAX);
	~stack(); //

    void push(T data);
    void pop();
    T peak();

	int size();
	bool empty();

    void duplicateCapacity();
};


template<typename T>
stack<T>::stack(int size) {
    capacity = size;
    T arr [capacity] = {};
    data = arr;
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
    if (top == 0)
        throw std::out_of_range ("Empty stack");
    else
    {
        top--;
        this->data[top] = 0;
    }
}

template<typename T>
T stack<T>::peak() {
    if (top == 0)
        throw std::out_of_range ("Empty stack");
    else
        return this->data[top];
}

template<typename T>
int stack<T>::size() {
    return top;
}

template<typename T>
bool stack<T>::empty() {
    if (top == 0)
        return true;
    else
        return false;
}

template<typename T>
void stack<T>::duplicateCapacity(){
    capacity *= 2;
    T array [capacity] = {};
    for (int i = 0; i<capacity/2; i++)
        array [i] = this->data[i];
    this->data = array;
}

template<typename T>
stack<T>::~stack() {
    delete this->data;
}

#endif