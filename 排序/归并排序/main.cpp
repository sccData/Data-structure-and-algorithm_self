#include <iostream>

using namespace std;

void merge_sort_c(int a[], int p, int r);
void merge(int a[], int p, int q, int r);

void merge_sort(int a[], int n)
{
    merge_sort_c(a, 0, n-1);
}

void merge_sort_c(int a[], int p, int r)
{
    if(p >= r)
        return;
    int q = (p + r)/2;
    merge_sort_c(a, p, q);
    merge_sort_c(a, q+1, r);
    merge(a, p, q, r);
}

void merge(int a[], int p, int q, int r)
{
    int i = p, j = q+1, k = 0;
    int temp[r-p+1];
    while(i <= q && j <= r)
    {
        if(a[i] <= a[j])
        {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    int start = i, end = q;
    if(j<=r) {
        start = j;
        end = r;
    }
    for(int n=start; n<=end; ++n)
    {
        temp[k++] = a[n];
    }
    for(int m=0; m<k; ++m)
    {
        a[m+p] = temp[m];
    }

}
int main()
{
    int a[6] = {9, 8, 7, 6, 5, 4};
    merge_sort(a, 6);
    for(int i=0; i<6; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}