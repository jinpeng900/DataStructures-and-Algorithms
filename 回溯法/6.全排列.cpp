#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void backtrack(vector<vector<int>> &res , vector<int>&outputs , int first , int len){
        if (first == len){
            res.push_back(outputs);
            return;
        }

        for (int i = first ; i < len ; ++i){
            swap(outputs[first] , outputs[i]);
            backtrack(res , outputs , first+1 , len);
            swap(outputs[first] , outputs[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> res;
        backtrack(res , nums , 0 , nums.size());
        return res;
    }
};