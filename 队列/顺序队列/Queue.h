//
// Created by scc on 19-6-18.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>
template <class T>
class Queue{
public:
    Queue(int n);
    ~Queue();
    void push(T data);
    T pop();
    T peek();
    int get_Size();

private:
    int size;
    int flag;
    int head;
    int tail;
    T *array;
};

template <class T>
Queue<T>::Queue(int n) {
    array = new T[n];
    size = n;
    head = 0;
    tail = 0;
    flag = 0;
}

template <class T>
void Queue<T>::push(T data) {
    if(tail == size) {
        if(head == 0)
        {
            std::cout << "No space" << std::endl;
            return;
        } else {
            for(int i = head; i < size; ++i)
            {
                array[i-head] = array[i];
            }
            head = 0;
            tail = flag;
        }
    }
    array[tail++] = data;
    flag++;
}

template <class T>
T Queue<T>::pop() {
    if(head == tail)
    {
        std::cout << "No data" << std::endl;
        return 0;
    }
    return array[head++];
}

template <class T>
T Queue<T>::peek() {
    return array[head];
}

template <class T>
int Queue<T>::get_Size() {
    return flag;
}

template <class T>
Queue<T>::~Queue() {
    delete[] array;
}
#endif //QUEUE_QUEUE_H
