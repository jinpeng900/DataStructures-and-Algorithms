#include<bits/stdc++.h>
using namespace std;

int h[100010] , w[100010];
int n , k;                      // n 块巧克力，k 个人

bool check(int d){              // 检查够不够分 , d 是边长
    int num = 0;
    for (int i = 0 ; i < n ; i++) num += (h[i] / d) * (w[i] / d);
    if (num >= k) return true;              // 够分
    else return false;                      // 不够分
}


int main()
{
    cin >> n >> k;
    for (int i = 0 ; i < n ; i++) cin >> h[i] >> w[i];
    int d= 1;               // 正方形边长
    while (1){
        if (check(d)) d++;
        else break;
    }
    cout << d - 1 << endl;  
    return 0;
}