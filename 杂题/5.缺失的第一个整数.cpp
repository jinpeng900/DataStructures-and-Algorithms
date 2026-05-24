#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>&nums){
    unordered_map<int , int>path;
    for (auto& num : nums){
        path[num]++;
    }

    int n = nums.size();

    for (int i = 1 ; i <= n + 1 ; i++){
        if (path.find(i) == path.end()){
            return i;
        }
    }
    return 1;
}