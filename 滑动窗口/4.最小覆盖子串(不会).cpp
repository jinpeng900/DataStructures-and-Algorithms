#include<bits/stdc++.h>
using namespace std;



string minWindow(string s , string t){
    unordered_map<char , int> ori , cnt;

    for (auto& p : s){
        ori[p]++;
    }

    int ls = s.size() , lt = t.size();
    if (ls < lt) return "";

    int len = lt;

    while (len < ls){
        int  i = 0;
        while (i < ls - len + 1){
            string sub = s.substr(i , len);
            for (auto& p : sub){
                cnt[p]++;
            }
            bool flag = true;
            for (auto& p : t){
                if (cnt[p] < ori[p]){
                    flag = false;
                    break;
                }
            }
            if (flag) return sub;
            cnt.clear();
            i++;
        }
        len++;
    }
    return "";
}