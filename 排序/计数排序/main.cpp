#include <iostream>
#include <vector>

using namespace std;

void CountingSort(int a[], int n)
{
    if(n <= 1)
        return;
    int max = a[0];
    for(int i=1; i<n; ++i)
    {
        max = (max > a[i]) ? max : a[i];
    }

    vector<int> temp(max+1, 0);
    for(int i=0; i<n; ++i)
    {
        temp[a[i]]++;
    }

    for(int i=1; i<max+1; ++i)
    {
        temp[i] += temp[i-1];
    }

    vector<int> tmp(n, 0);

    // 从末尾开始遍历，保证计数排序是稳定的排序
    for(int i=n-1; i>=0; --i)
    {
        tmp[temp[a[i]]-1] = a[i];
        temp[a[i]]--;
    }

    for(int i=0; i<n; ++i)
    {
        a[i] = tmp[i];
    }
}

int main()
{
    int a[5] = {5, 4, 3, 2, 1};
    CountingSort(a, 5);
    for(auto b:a)
        cout << b << " ";
    return 0;

}