# include<bits/stdc++.h>
using namespace std;
// 重要重要
int longestConsecutive(vector<int>& nums){
    int n = nums.size();
     if (n == 0){
        return 0;
    }
    unordered_set<int> path;
    for (int i = 0 ; i < n ; i++){
        path.insert(nums[i]);
    }

    int ans = 1;
    
    for (auto& a : path){
        if (!path.count(a - 1)){
            int temp = 1;
            int b = a;
            while (path.find(b+1) != path.end()){
                temp++;
                b++;
            }
            ans = max(temp , ans);
        }
    }

    return ans;
}


int main(){
    vector<int> nums{100,4,200,1,3,2};
    cout << longestConsecutive(nums) << endl;
    return 0;
}