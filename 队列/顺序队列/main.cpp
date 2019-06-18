#include "Queue.h"
#include <string>
using namespace std;
int main()
{
    Queue<int> q(6);
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop() << endl;
    cout << q.peek() << endl;
    return 0;
}