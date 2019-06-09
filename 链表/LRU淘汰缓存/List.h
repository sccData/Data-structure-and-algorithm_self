//
// Created by scc on 19-6-9.
//

#ifndef LRU_LIST_H
#define LRU_LIST_H

#include <iostream>
typedef struct Node {
    int num;
    struct Node *next;
} NODE, *PNODE;

PNODE init()
{
    PNODE head = new NODE;
    head->next = nullptr;
    return head;
}

bool insert(PNODE head, int index, int data)
{
    if(index <= 0)
        return false;
    PNODE temp = head;
    int i = 0;
    while(temp != nullptr && i < index-1)
    {
        temp = temp->next;
        ++i;
    }
    if(i < index-1)
        return false;
    PNODE current = new NODE;
    current->num = data;
    current->next = temp->next;
    temp->next = current;
    return true;
}

bool delete_k(PNODE head, int index)
{
    if(index <= 0)
        return false;
    PNODE temp = head;
    int i;
    while(temp != nullptr && i < index-1)
    {
        temp = temp->next;
        ++i;
    }
    if(i < index-1 || temp->next == nullptr)
        return false;
    PNODE current = temp->next;
    temp->next = current->next;
    delete current;
    return true;
}

void delete_all(PNODE head)
{
    PNODE temp = head;
    while(temp != nullptr)
    {
        head = temp;
        temp = temp->next;
        delete head;
    }
}

int find_num(PNODE head, int data)
{
    PNODE temp = head->next;
    int i = 1;
    while(temp != nullptr)
    {
        if(temp->num == data)
        {
            return i;
        }
        temp = temp->next;
        ++i;
    }
    return 0;
}

void print_num(PNODE head)
{
    PNODE temp = head->next;
    while(temp != nullptr)
    {
        std::cout << temp->num << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
#endif //LRU_LIST_H
