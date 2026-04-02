#include<bits/stdc++.h>
using namespace std;

int a[101000];
int p(int deep){                // 返回第 deep 层的结点数量
    return pow(2 , deep);       
}

int main()
{
    int n , mindeep = 1 , i = 2 , deep = 2;
    cin >> n;
    cin >> a[1];
    long long maxx = a[1];                      // 最大权值初值为第一层的和
    for(i = 2 ; i <= n ; i++){
        cin >> a[i];
    }
    i = 2;
    while (i <= n)
    {
        long long sum = 0;
        for (; i < p(deep) ; i++){
            sum += a[i];                // 计算第 deep 层的和
        }
        if (sum > maxx){
            maxx = sum;
            mindeep = deep;
        }
        deep++;
    }
    cout << mindeep << endl;
    return 0;
}