//
// Created by scc on 19-6-21.
//

#ifndef CIRCLE_QUEUE_QUEUE_H
#define CIRCLE_QUEUE_QUEUE_H

#include <iostream>

template <class T>
class Queue{
public:
    Queue(int n);
    ~Queue();
    void push(T data);
    T pop();
    int get_size();
    T peek();

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
    flag = 0;
    head = 0;
    tail = 0;
}

template <class T>
void Queue<T>::push(T data) {
    if((tail+1)%size == head)
    {
        std::cout << "no space" << std::endl;
        return;
    }

    array[tail] = data;
    tail = (tail+1) % size;
    flag++;
}

template <class T>
T Queue<T>::pop() {
    if(head == tail)
    {
        std::cout << "no data" << std::endl;
        return 0;
    }
    T ret = array[head];
    head = (head + 1) % size;
    flag--;
    return ret;
}

template <class T>
T Queue<T>::peek() {
    if(head == tail)
    {
        std::cout << "no data" << std::endl;
        return 0;
    }

    return array[head];
}

template <class T>
int Queue<T>::get_size() {
    return flag;
}

template <class T>
Queue<T>::~Queue() {
    delete[] array;
}
#endif //CIRCLE_QUEUE_QUEUE_H
