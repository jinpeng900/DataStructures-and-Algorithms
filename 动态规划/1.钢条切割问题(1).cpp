/*
    钢条切割问题
     给定一个长度为 n 的钢条和一个价格表 p[i] (i = 1,2,...,n)
     请你计算切割钢条的方案，使得收益最大
*/
// 效率 O(n^2)
# include<bits/stdc++.h>
using namespace std;

int ans(int n , int p[]){
    int r[n];
    r[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        int res = -1;
        for(int j = 1 ; j <= i ; j++){
            res = max(res , p[j] + r[i - j]);
        }
        r[i] = res;
    }
    return r[n];
}
