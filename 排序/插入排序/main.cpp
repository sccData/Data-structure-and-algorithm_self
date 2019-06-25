#include <iostream>
using namespace std;

void insertion_Sort(int a[], int n)
{
    if(n <= 1)
        return;
    for(int i = 1; i < n; ++i)
    {
        int value = a[i];
        int j = i - 1;
        for(; j >= 0; --j)
        {
            if(a[j] > value)
            {
                a[j+1] = a[j];
            } else {
                break;
            }
        }
        a[j+1] = value;
    }
}
int main()
{
    int a[6] = {4, 5, 6, 1, 3, 2};
    insertion_Sort(a, 6);
    for(int i = 0; i < 6; ++i)
        cout << a[i] << " ";
    return 0;
}