#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;
/*
 * 基于栈实现一个浏览器前进和后退的功能
 */
int main()
{
    Stack<string> s1(10);
    Stack<string> s2(10);
    string tmp;

    while(cin>>tmp)
    {
        if(tmp == "b")
        {
            // string temp = s1.pop();
            s2.push(s1.pop());
            cout << s1.peek() << endl;

        } else if(tmp == "f")
        {
            cout << s2.peek() << endl;
            s1.push(s2.pop());
        } else {
            cout << tmp << endl;
            s1.push(tmp);
            while(s2.stackSize() != 0)
            {
                s2.pop();
            }
        }
    }

    return 0;
}