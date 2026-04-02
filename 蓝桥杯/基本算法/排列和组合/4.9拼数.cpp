#include <bits/stdc++.h>
using namespace std;

string str[21];

bool cmp(string a , string b)
{
    return a+b > b+a;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> str[i];
    } 
    sort(str+1 , str+n+1 , cmp);
    for (int i = 1 ; i <= n ; i++)
    {
        cout << str[i];
    }
    return 0;
}