# include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    sort(intervals.begin() , intervals.end());
    vector<vector<int>> ans;

    int n = intervals.size();
    if (n == 0){
        return {};
    }

    for (auto&t : intervals){
        int i = t[0];
        int j = t[1];

        if (ans.empty() || ans.back()[1] < i){
            ans.push_back({i , j});
        }
        else{
            ans.back()[1] = max(ans.back()[1] , j);
        }
    }
    return ans;
}