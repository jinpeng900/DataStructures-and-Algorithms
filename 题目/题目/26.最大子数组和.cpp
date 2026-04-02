#include<bits\stdc++.h>
// 动态规划
using namespace std;

int maxSubArray(vector<int>& nums)
{
    int pre = 0;
    int max_num = 0;
    for (const auto &x : nums)
    {
        pre = max(pre + x , x);
        max_num = max(pre , max_num);
    }
    return max_num;
}