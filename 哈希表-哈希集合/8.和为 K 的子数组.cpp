# include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums , int k){
    int ans = 0;
    unordered_map<int , int> mp;
    mp[0] = 1;
    int pre = 0;

    for(auto&x : nums){
        pre += x;

        if (mp.find(pre - k) != mp.end()) {
            ans += mp[pre - k];
        }

        mp[pre]++;
    }

    return ans;
}

