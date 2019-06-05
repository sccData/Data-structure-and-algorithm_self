//
// Created by scc on 19-6-4.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>
typedef struct Node {
    int data;
    struct Node *next;
} NODE, *PNODE;

PNODE init()
{
    PNODE head = new NODE;     // 哨兵
    // PNODE root = new NODE;
    head->next = nullptr;
    // root->data = data;
    // root->next = nullptr;

    return head;
}

bool insert(PNODE head, int num, int data)
{
    PNODE temp = head;
    int i = 0;
    while(temp!=nullptr && i<num-1)
    {
        temp = temp->next;
        ++i;
    }
    if(i<num-1)
    {
        std::cerr << "插入位置有误" << std::endl;
        return false;
    }
    PNODE current = new NODE;
    current->data = data;
    current->next = temp->next;
    temp->next = current;
    return true;
}

void print(PNODE head)
{
    PNODE temp = head->next;
    while(temp != nullptr)
    {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
    std::cout << std::endl;
}

void delete_list(PNODE head)
{
    PNODE temp = head;
    PNODE current;
    while(temp != nullptr)
    {
        current = temp;
        temp = current->next;
        delete current;
    }
}

#endif //LIST_LIST_H
