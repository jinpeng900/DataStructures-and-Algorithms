#include<bits/stdc++.h>

using namespace std;


vector<int> twoSum(vector<int>& nums , int target)
{
    unordered_map<int , int> hashtable;
    int count = nums.size();
    for (int i = 0 ; i < count ; i++)
    {
        hashtable[nums[i]] = i;
    }
    for (int i = 0 ; i < count ; i++)
    {
        auto it = hashtable.find(target - nums[i]);
        if (it != hashtable.end() && i != it->second)
        {
            return {i , it->second};
        }
    }
    return {};
}



int main()
{
    vector<int>nums = {2 , 7 , 11 , 15};
    int target = 17;
    vector<int>ans = twoSum(nums , target);
    int len = ans.size();
    for (int i = 0 ; i < len ; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
