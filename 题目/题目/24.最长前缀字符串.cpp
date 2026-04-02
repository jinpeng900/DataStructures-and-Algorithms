#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        string str = "";
        string first = strs[0];
        int len = first.length();
        for (int i = 0 ; i < len ; i++)
        {
            char p = first[i];
            for (string s : strs)
            {
                if (s[i] != p || i == s.length())
                {
                    return str;
                }
            }
            str += p;
        }
        return str;
    }




