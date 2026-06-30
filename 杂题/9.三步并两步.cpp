#include<bits/stdc++.h>
using namespace std;


long long solve(int current, int b) {
    // 成功到达目标
    if (current == b) {
        return 1;
    }
    // 超出目标，此路径无效
    if (current > b) {
        return 0;
    }
    
    // 递归计算：加 2 的路径数 + 加 3 的路径数
    return solve(current + 2, b) + solve(current + 3, b);
}