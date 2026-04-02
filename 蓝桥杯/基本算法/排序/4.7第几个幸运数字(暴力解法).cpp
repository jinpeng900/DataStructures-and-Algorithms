/*

一个整数如果只含有因子 3 , 5 , 7 , 则称其为幸运数字。
例如：
15 是幸运数字，因为它只含有因子 3 和 5。
21 不是幸运数字，因为它含有因子 2。
35 是幸运数字，因为它只含有因子 5 和 7。
现在，给定一个整数 59084709587505 ，请你计算出这儿是第几个幸运数字。

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n = 59084709587505;
    int cnt = 0;
    for (int i = 0 ; pow(3 , i) <= n ; i++){
        for (int j = 0 ; pow(5 , j) <= n ; j++){
            for (int k = 0 ; pow(7 , k) <= n ; k++){
                if (pow(3 , i) * pow(5 , j) * pow(7 , k) <= n) cnt++;
            }
        }
    }
    cout << cnt - 1 << endl;                // 幸运数字不包括 1
    return 0;
}