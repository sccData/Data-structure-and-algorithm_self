#include "Queue.h"
using namespace std;

int main()
{
    Queue<int> q(10);
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    return 0;
}