# include<bits/stdc++.h>
using namespace std;


vector<int> findAnagrams(string s , string p){
    vector<int> ans;
    int s_len = s.size();
    int p_len = p.size();
    if (s_len < p_len){
        return {};
    }

    vector<int> p_Count(26 , 0);
    vector<int> s_Count(26 , 0);
    
    for (int i = 0 ; i < p_len ; ++i){
        ++p_Count[p[i] - 'a'];
        ++s_Count[s[i] - 'a'];
    }

    if (p_Count == s_Count){
        ans.push_back(0);
    }

    for (int j = p_len ; j < s_len ; j++){
        --s_Count[s[j - p_len] - 'a'];
        ++s_Count[s[j] - 'a'];
        if (s_Count == p_Count){
            ans.push_back(j - p_len + 1);
        }
    }
    return ans;
}