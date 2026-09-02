#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<vector<int>> ans;
    
    void dfs(vector<int>&cur , vector<int>&nums , int index){
        ans.push_back(cur);
        for (int i = index ; i < nums.size() ; i++){
            cur.push_back(nums[i]);
            dfs(cur , nums , i+1);
            cur.pop_back();
        }    
    }

    vector<vector<int>> subsets(vector<int>& nums){
        vector<int>cur;
        dfs(cur , nums , 0);
        return ans;
    }
};