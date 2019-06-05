#include "List.h"
#include <stack>
#include <algorithm>

// 判断是否是回文字符串
bool is_Palindrome(PNODE head)
{
    std::stack<int> s;
    PNODE fast = head->next;
    PNODE slow = head->next;
    while(fast != nullptr && fast->next != nullptr)
    {
        s.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(s.empty())
        return true;
    // s.pop();
    if(fast != nullptr)
        slow = slow->next;
    while(slow!= nullptr)
    {
        if(s.top()!=slow->data) {
            std::cout << s.top() << " " << slow->data << std::endl;
            return false;
        }
        s.pop();
        slow = slow->next;
    }
    return true;
}

int main() {
    PNODE head = init();
    insert(head, 1, 1);
    insert(head, 2, 1);
    insert(head, 3, 3);
    insert(head, 4, 4);
    insert(head, 5, 3);
    insert(head, 6, 2);
    insert(head, 7, 1);
    print(head);
    if(is_Palindrome(head))
        std::cout << "right" << std::endl;
    else
        std::cout << "false" << std::endl;
    delete_list(head);
    return 0;
}