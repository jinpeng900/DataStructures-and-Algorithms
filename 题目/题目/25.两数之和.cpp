#include<bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums , int target)
{
    vector<int>ans;
    int count = nums.size();
    for (int i = 0 ; i < count - 1 ; i++)
    {
        for (int j = i + 1 ; j < count ; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i , j};
            }
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