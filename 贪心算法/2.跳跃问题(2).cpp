# include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums){
    int end = 0;
    int n = nums.size();
    int max_pos = 0;
    int steps = 0;
    for (int i = 0 ; i < n - 1 ; i++){
        max_pos = max(max_pos , i+nums[i]);
        if (i == end){
            end = max_pos;
            steps++;
        }
        if (end >= n-1){
            return steps;
        }
    }
    return steps;
}