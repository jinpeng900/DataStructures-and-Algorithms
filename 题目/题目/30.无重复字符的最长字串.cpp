#include<bits/stdc++.h>
using namespace std;
// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>Hashmap;
        int res=0;
        int n=s.size();
        for(int i=0,j=0;i<n;i++)
        {
            Hashmap[s[i]]++;
            while(Hashmap[s[i]] > 1)
            {
                Hashmap[s[j]] --;
                j++;
            }
            res=max(res,i-j+1);
        }
        return res;
    }
};