/*
 * LRU缓存淘汰：维护一个有序的单链表，越靠近链表尾部的结点是越早之前访问的。当有一个新的数据被访问时，从链表头开始顺序遍历链表。
 * 1. 如果此数据之前已经被缓存在链表中了，我们遍历得到这个数据对应的结点，并将其从原来的位置删除，然后再插入到链表头部
 * 2. 如果此数据没有在缓存链表中，又可以分为两种情况:
 *    如果此时缓存未满，则将此结点直接插入到链表头部；
 *    如果此时缓存已满，则链表尾结点删除，将新的数据结点插入链表的头部
 */
#include "List.h"
using namespace std;

int main() {
    PNODE head = init();
    int count = 0;
    int num = 0;
    int index = 0;
    while(cin >> num)
    {
        if(count < 7)
        {
            count++;
            insert(head, num, count);
            print_num(head);
            // cout << count << endl;
        } else {
            index = find_num(head, num);
            if(index == 0) {
                delete_k(head, 7);
                insert(head, 1, num);
                print_num(head);
            } else {
                delete_k(head, index);
                insert(head, 1, num);
                print_num(head);
            }
        }
    }
    delete_all(head);
    return 0;
}