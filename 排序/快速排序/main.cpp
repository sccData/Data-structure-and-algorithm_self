#include <iostream>
using namespace std;

int partition(int a[], int p, int r)
{
    int plot = a[r];
    int i = p;
    int temp = 0;
    for(int j=p; j<r; ++j) {
        if (a[j] < plot) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            ++i;
        }
    }
    a[r] = a[i];
    a[i] = plot;
    return i;
}
void quick_sort_c(int a[], int p, int r)
{
    if(p >= r)
        return;
    int q = partition(a, p, r);
    quick_sort_c(a, p, q-1);
    quick_sort_c(a, q+1, r);
}
void quick_sort(int a[], int n)
{
    quick_sort_c(a, 0, n-1);
}
int main()
{
    int a[6] = {1, 4, 7, 3, 2, 5};
    quick_sort(a, 6);
    for(int i=0; i<6; ++i)
        cout << a[i] << " ";
    return 0;
}