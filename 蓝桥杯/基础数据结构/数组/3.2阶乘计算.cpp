#include<iostream>

/*
输入一个正整数 n ， 输出 n! 的值 ， n <= 1000
*/

using namespace std;

const int N = 10000;
int a[N] = {0};                     // 存结果 ， 大静态数组要定义在全局之中
int main()
{
    int n;
    cin >> n;
    a[0] = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        int carry = 0;
        for (int j = 0 ; j < N ; j++)
        {
            a[j] = a[j] * i + carry;
            carry = a[j] / 10;
            a[j] = a[j] % 10;
        }
    }
    int last;
    for (int i = N - 1 ; i >= 0 ; i--)
    {
        if (a[i] != 0)
        {
            last = i;
            break;
        }
    }
    for (int i = last ; i >= 0 ; i--)
    {
        
        cout << a[i];
    }



    return 0;
}