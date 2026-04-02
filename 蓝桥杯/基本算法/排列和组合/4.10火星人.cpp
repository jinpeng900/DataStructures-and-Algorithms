#include <bits/stdc++.h>
using namespace std;

int a[10000000];

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int b;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    for (b = 0 ; b < m ; b++)
    {
        next_permutation(a , a + n);
    }
    for (int i = 0 ; i < n ; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}