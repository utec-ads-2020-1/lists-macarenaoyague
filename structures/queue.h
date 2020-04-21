#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

using namespace std;

#define MAX 1000 

// TODO: Implement all methods
template <typename T>
class queue {
	T* data;
	int top;
	int capacity;

public:
    queue(int size = MAX);
    ~queue();

    void push(T data);
    void pop();
    T front();
    T back();

	int size();
	bool empty();

    void duplicateCapacity();
};

template<typename T>
queue<T>::queue(int size) {
    capacity = size;
    T arr[capacity] = {};
    this->data = arr;
    top = 0;
}

template<typename T>
void queue<T>::push(T data) {
    if (top == capacity)
        duplicateCapacity();
    this->data[top] = data;
    top++;
}

template<typename T>
void queue<T>::pop() {
    if (empty())
        throw std::out_of_range("Empty queue");
    else
    {
        top--;
        for (int i = 0; i<top; i++)
            this->data[i] = this->data[i+1];
        this->data[top] = 0;
    }
}

template<typename T>
T queue<T>::front() {
   // return this->data[];
}

template<typename T>
T queue<T>::back() {
    //
    return nullptr;
}

template<typename T>
int queue<T>::size() {
    return top;
}

template<typename T>
bool queue<T>::empty() {
    return size() == 0;
}

template<typename T>
void queue<T>::duplicateCapacity(){
    capacity *= 2;
    T array [capacity] = {};
    for (int i = 0; i<capacity/2; i++)
        array [i] = this->data[i];
    this->data = array;
}

#endif