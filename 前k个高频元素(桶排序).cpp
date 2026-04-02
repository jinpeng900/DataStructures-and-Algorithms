# include<bits\stdc++.h>
using namespace std;


vector<int> &topKFrequent(vector<int>& nums, int k) {
    unordered_map<int , int> count;
    for (auto &i : nums){
        count[i]++;
    }
    vector<vector<int>> bucket(nums.size() + 1);
    for (auto& i : count){
        bucket[i.second].push_back(i.first);
    }
    vector<int> ans;
    for (int i = bucket.size() - 1 ; i >= 0 && ans.size() < k ; i--){
        for (auto& j : bucket[i]){
            ans.push_back(j);
            if (ans.size() == k) break;


            
        }
    }
    return ans;
}