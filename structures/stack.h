#ifndef STACK_H
#define STACK_H

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
};




template<typename T>
stack<T>::stack(int size) {

}

template<typename T>
void stack<T>::push(T data) {

}

template<typename T>
void stack<T>::pop() {

}

template<typename T>
T stack<T>::peak() {
    return nullptr;
}

template<typename T>
int stack<T>::size() {
    return 0;
}

template<typename T>
bool stack<T>::empty() {
    return false;
}


#endif