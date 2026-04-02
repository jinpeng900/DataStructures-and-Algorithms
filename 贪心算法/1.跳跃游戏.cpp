# include<bits/stdc++.h>
using namespace std;

bool canjump(vector<int> & nums){
    int n = nums.size();
    int end = 0;
    int max_len = 0;

    for (int i = 0 ; i < n - 1 ; i++){
        max_len = max(max_len , i + nums[i]);
        if (i == end){
            end = max_len;
        }
    }
    if (end >= n-1){
        return true;
    }
    return false;

}
