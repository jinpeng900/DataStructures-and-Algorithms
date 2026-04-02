#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int h[N] , w[N];
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
    int L = 1 , R =  N;
    // 第一种写法
    while (L < R){
        int mid = (L + R + 1) >> 1;             // 除以 2 , 向右取整
        if (check(mid)) L = mid;
        else R = mid - 1;
    }

    cout << L << endl;

    return 0;
}