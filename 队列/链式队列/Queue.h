//
// Created by scc on 19-6-21.
//

#ifndef QUEUE_LIST_QUEUE_H
#define QUEUE_LIST_QUEUE_H

#include <iostream>

template <class T>
class Queue{
public:
    Queue();
    ~Queue();
    void push(T data);
    T pop();
    T peek();
    int get_size();

private:
    struct Node{
        T fist;
        struct Node *next;
    };
    Node *head;
    Node *tail;
    int flag;
};

template <class T>
Queue<T>::Queue() {
    head = new Node;
    head->next = nullptr;
    flag = 0;
    tail = head;
}

template <class T>
void Queue<T>::push(T data) {
    Node *tmp = new Node;
    tmp->fist = data;
    tmp->next = nullptr;
    tail->next = tmp;
    tail = tmp;
    flag++;
}

template <class T>
T Queue<T>::pop() {
    if(head == tail)
    {
        std::cout << "no data" << std::endl;
        return 0;
    }
    if(head->next == tail)
        tail = head;
    T temp = head->next->fist;
    Node *tmp = head->next;
    head->next = head->next->next;
    delete tmp;
    flag--;
    return temp;
}

template <class T>
T Queue<T>::peek() {
    if(head == tail)
    {
        std::cout << "no data" << std::endl;
        return 0;
    }
    return head->next->fist;
}

template <class T>
int Queue<T>::get_size() {
    return flag;
}

template <class T>
Queue<T>::~Queue() {
    Node *temp;
    while(head != tail)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    delete tail;
}
#endif //QUEUE_LIST_QUEUE_H
