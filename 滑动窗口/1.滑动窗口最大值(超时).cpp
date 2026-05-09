# include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums , int k){
    int n = nums.size();
    vector<int>ans;

    for (int i = 0 ; i <= n-k ; ++i){
        int num = *max_element(nums.begin()+i , nums.begin()+i+k);
        ans.push_back(num);
    }

    return ans;

}