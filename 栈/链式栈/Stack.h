//
// Created by scc on 19-6-16.
//

#ifndef STACKBASEDONLINKED_STACK_H
#define STACKBASEDONLINKED_STACK_H

#include <iostream>
template <class T>
class Stack{
public:
    Stack();
    ~Stack();
    T peek();
    void push(const T& data);
    T pop();
    int size() const;

private:
    struct Node{
        T data;
        struct Node *next;
    };

    int count;
    struct Node *head;
};

template <class T>
Stack<T>::Stack() {
    head = new Node;
    head->next = nullptr;
    count = 0;
}

template <class T>
Stack<T>::~Stack() {
    Node *temp = head;
    while(temp != nullptr)
    {
        head = temp;
        temp = temp->next;
        delete head;
    }
    head = nullptr;
    count = 0;
}

template <class T>
void Stack<T>::push(const T &data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
    count++;
}

template  <class T>
int Stack<T>::size() const {
    return count;
}

template  <class T>
T Stack<T>::pop() {
    if(count == 0)
    {
        std::cout << "no data" << std::endl;
        return 0;
    }
    T tmp = head->next->data;
    Node *temp = head->next;
    head->next = temp->next;
    delete temp;
    count--;
    return tmp;
}

template <class T>
T Stack<T>::peek() {
    if(count == 0)
    {
        std::cout << "no data" << std::endl;
        return 0;
    }
    return head->next->data;
}

#endif //STACKBASEDONLINKED_STACK_H
