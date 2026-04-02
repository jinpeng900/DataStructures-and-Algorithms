#include<bits/stdc++.h>
using namespace std;

int a[1000];

int bin_search(int *a , int n , int x){
    int left = 0 , right = n;
    while (left < right){
        int mid = left + (right - left) / 2;
        if (a[mid] > x) right = mid-1;
        else if (a[mid] < x) left = mid + 1;
        else return mid;
        cout << a[mid] << " ";
    }
    return -1;
}

int main()
{
    int n = 100;
    for (int i = 0 ; i < n ; i++) a[i] = i + 1;
    int test = 51;
    int res = bin_search(a , n , test);
    cout << endl << res << endl;
    return 0;
}