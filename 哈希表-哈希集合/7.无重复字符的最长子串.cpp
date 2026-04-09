# include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
    int n = s.length();

    unordered_set<char> dp;

    int ans = 0;
    int pos = 0;
 
    for (int i = 0 ; i < n ; i++){
        if (i != 0){
            dp.erase(s[i-1]);
        }

        while (pos < n && dp.count(s[pos]) == 0){
            dp.insert(s[pos]);
            pos++;
        }

        ans = max(ans , pos - i + 1);

    }
    return ans;

}