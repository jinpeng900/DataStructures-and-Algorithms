#include<bits/stdc++.h>
using namespace std;

int len , n , m;
int stone[50005];

bool check(int d)           // 检查距离 d 是否合适
{
    int num = 0;                // num 记录搬走岩石的数量
    int pos = 0;                // 当前站立的位置
    for (int i = 1 ; i <= n ; i++)
    {
        if(stone[i] - pos < d) num++;           // 第 i 块岩石可以搬走 
        else pos = stone[i];            // 第 i 块岩石不能搬走，更新当前站立的位置
    }
    if (num <= m) return true;              // 要移动的岩石数量不超过 m，距离 d 合适
    else return false;                      // 要移动的岩石数量超过 m，距离 d 不合适
}

int main()
{
    cin >> len >> n >> m;
    for(int i = 1 ; i <= n ; i++) cin >> stone[i];
    int L = 0 , R = len , mid;
    while(L < R)
    {
        mid = (L + R + 1) / 2;
        if(check(mid)) L = mid;                 // 距离 d 合适，尝试更大的距离
        else R = mid - 1;                       // 距离 d 不合适，尝试更小的距离
    }
    cout << L << endl;
    return 0;
}