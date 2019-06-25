#include <iostream>
using namespace std;

void selection_Sort(int a[], int n)
{
    if(n <= 1)
        return;
    for(int i = 0; i < n-1; ++i)
    {
        int min = i;
        for(int j = i+1; j < n; ++j)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
int main()
{
    int a[6] = {4, 5, 6, 3, 2, 1};
    selection_Sort(a, 6);
    for(int i = 0; i < 6; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}