#include <iostream>
using namespace std;

void bubble_Sort(int a[], int n)
{
    if(n <= 1)
        return;
    bool flag = true;
    for(int i = 0; i < n; ++i)
    {
        flag = false;
        for(int j = 0; j < n-i-1; ++j)
        {
            if(a[j] > a[j+1])
            {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = true;
            }
        }

        if(!flag)
            break;
    }
}

int main()
{
    int a[6] = {4, 5, 6, 3, 2, 1};
    bubble_Sort(a, 6);
    for(int i = 0; i < 6; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}