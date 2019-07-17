#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <random>
#include <ctime>
using namespace std;

const int MAX_LEVEL = 16;    // 跳表最大层数

class Node {
public:
    Node();
    ~Node() {}
    void set_data(int _data) { data = _data; }
    int get_data() { return data; }

    void set_max_level(int _max_level) { max_level = _max_level; }
    int get_max_level() { return max_level; }

    Node **get_next() { return next; }
private:
    int data;            // 记录数据
    int max_level;       // 该结点目前最大的层数
    Node *next[MAX_LEVEL];    // 记录该结点每层的下一个结点
};

Node::Node() {
    data = -1;
    max_level = 0;
    for(int i; i<MAX_LEVEL; ++i)
    {
        next[i] = nullptr;
    }
}

class skip_list {
public:
    skip_list();
    ~skip_list() {}

    Node* find(int data);
    void insert(int data);
    void PrintAll();
    void PrintAll(int l);
    int Delete(int data);
    int RandomLevel();

private:
    int levelcount;
    Node *head;     // 带头结点
};

skip_list::skip_list() {
    levelcount = 1;
    head = new Node();
}

Node* skip_list::find(int data) {
    Node* lpNode = head;
    for(int i = levelcount-1; i >= 0; --i)
    {
        while((lpNode->get_next()[i] != nullptr) && (lpNode->get_next()[i]->get_data() < data))
        {
            lpNode = lpNode->get_next()[i];
        }
    }

    if((lpNode->get_next()[0] != nullptr) && (lpNode->get_next()[0]->get_data() == data))
        return lpNode->get_next()[0];
    return nullptr;
}

void skip_list::insert(int data) {
    Node* new_Node = new Node();
    if(new_Node == nullptr)
        return;
    int level = RandomLevel();
    new_Node->set_data(data);
    new_Node->set_max_level(level);

    Node* lpUpdateNode[level];
    for(int i=0; i<level; ++i)
    {
        lpUpdateNode[i] = head;
    }
    Node* lpNode = head;
    for(int i=level-1; i>=0; --i)
    {
        while((lpNode->get_next()[i] != nullptr) && (lpNode->get_next()[i]->get_data() < data))
        {
            lpNode = lpNode->get_next()[i];
        }
        lpUpdateNode[i] = lpNode;
    }
    for(int i=0; i<level; ++i)
    {
        new_Node->get_next()[i] = lpUpdateNode[i]->get_next()[i];
        lpUpdateNode[i]->get_next()[i] = new_Node;
    }
    if(levelcount < level)
    {
        levelcount = level;
    }

}

int skip_list::Delete(int data) {
    int ret = -1;
    Node* lpUpdateNode[levelcount];
    Node* lpNode = head;

    for(int i = levelcount-1; i>=0; --i)
    {
        while((lpNode->get_next()[i] != nullptr) && (lpNode->get_next()[i]->get_data() < data))
        {
            lpNode = lpNode->get_next()[i];
        }
        lpUpdateNode[i] = lpNode;
    }

    if((lpNode->get_next()[0] != nullptr) && (lpNode->get_next()[0]->get_data() == data))
    {
        for(int i=levelcount-1; i >=0; --i)
        {
            if((lpUpdateNode[i]->get_next()[i] != nullptr) && (lpUpdateNode[i]->get_next()[i]->get_data() == data))
            {
                lpUpdateNode[i]->get_next()[i] = lpUpdateNode[i]->get_next()[i]->get_next()[i];
                ret = 0;
            }
        }
    }
    return ret;
}

void skip_list::PrintAll() {
    Node* lpNode = head;
    while(lpNode->get_next()[0] != nullptr)
    {
        cout << lpNode->get_next()[0]->get_max_level() << " " << lpNode->get_next()[0]->get_data() << endl;
        lpNode = lpNode->get_next()[0];
    }
}

void skip_list::PrintAll(int l) {
    for(int i=MAX_LEVEL-1; i>=0; --i)
    {
        Node* lpNode = head;
        cout << "第" << i << "级:" ;
        if((l<0) || ((l >= 0) && (l == i)))
        {
            while(lpNode->get_next()[i] != nullptr)
            {
                cout << lpNode->get_next()[i]->get_data() << " ";
                lpNode = lpNode->get_next()[i];
            }
            cout << endl;
            if(l >= 0)
                break;
        }
    }
}

int GetRandom()
{
    static int _count = 1;
    std::default_random_engine generator(time(0) + _count);
    std::uniform_int_distribution<int> distribution(1,99999/*0x7FFFFFFF*/);
    int dice_roll = distribution(generator);
    _count += 100;
    return dice_roll;
}

int skip_list::RandomLevel()
{
    int level = 1;
    for(int i=1; i<MAX_LEVEL; ++i){
        if(1 == (GetRandom()%3)){
            level++;
        }
    }
    return level;
}

int main()
{
    skip_list skipList;
    for(int i=1; i<50; ++i)
    {
        if((i%3) == 0)
            skipList.insert(i);
    }

    for(int i=1; i<50; ++i)
    {
        if((i%3) == 1)
            skipList.insert(i);
    }

    // skipList.PrintAll();
    skipList.PrintAll(-1);
    /* Node* lpNode = skipList.find(27);
    if(NULL != lpNode){
        cout << "查找值为27的节点,找到该节点,节点值:" << lpNode->get_data() << endl;
    }else{
        cout << "查找值为27的节点,未找到该节点" << endl;
    } */
    int ret = skipList.Delete(46);
    if(0 == ret){
        cout << "查找值为46的节点,找到该节点,并删除成功" << endl;
    }else{
        cout << "查找值为46的节点,找到该节点,删除失败" << endl;
    }
    cout << endl;
    //打印所有等级结构
    skipList.PrintAll(-1);
    return 0;
}
