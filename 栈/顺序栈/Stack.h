//
// Created by scc on 19-6-13.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

template <class T>
class Stack{
public:
    Stack(int count);
    ~Stack();
    T pop();
    void push(T data);
    int stackSize();
    int stackMaxSize();
    T& peek();
private:
    int size;
    int real;
    T *array;
};

template <class T>
Stack<T>::Stack(int count) {
    this->size = count;
    this->real = 0;
    this->array = new T[this->size];
}

template <class T>
T Stack<T>::pop()
{
    this->real--;
    T temp = this->array[this->real];
    return temp;
}

template <class T>
void Stack<T>::push(T data) {
    if(this->real == this->size)
    {
        this->size = 2*this->real;
        T *temp = new T[this->size];
        for(int i=0; i<this->real; ++i)
        {
            temp[i] = this->array[i];
        }
        delete[] this->array;
        this->array = temp;
    }
    this->array[this->real] = data;
    this->real++;
}

template <class T>
int Stack<T>::stackSize() {
    return this->real;
}

template <class T>
int Stack<T>::stackMaxSize() {
    return this->size;
}

template <class T>
T& Stack<T>::peek() {
  return this->array[this->real-1];
}

template <class T>
Stack<T>::~Stack() {
    delete[] array;
}
#endif //STACK_STACK_H
