#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
    long long p;      // 成本
    long long c;      // 次数
}a[200100];

bool cmp(node&a , node&b)
{
    return a.c < b.c;
}


int main()
{
    long long n;
    long long S;
    cin >> n >> S;
    for (long long i = 1 ; i <= n ; i++)
    {
        cin >> a[i].p >> a[i].c;
    }
    sort(a+1 , a+1+n , cmp);
    long long ans = 0;
    long long temp = 0;
    long long j = 1;
    long long count = 0;
    for (long long i = 1 ; i < n ; i++)
    {
        temp += a[i].p;
    }
    while (temp > S)
    {
        ans = S * (a[j].c);
        count = a[j].c;
        temp -= a[j].p;
        j++;
    }
    while (j <= n)
    {
        ans += a[j].p * (a[j].c - count);
        j++;
    }
    cout << ans << endl;

    



    return 0;
}