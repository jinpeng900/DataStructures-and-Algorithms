#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
    if (!strs.size())
    {
        return "";
    }
    string predix = strs[0];
    int count = strs.size();
    for (int i = 1 ; i < count ; i++)
    {
        predix = longestCommonPrefix(predix , strs[i]);
        if (!predix.size())
        {
            break;
        }
    }
    return predix;
}



string longestCommonPrefix(const string &str_a , const string &str_b) 
{
    int length = min(str_a.length() , str_b.length());
    int index = 0;
    while (index < length && str_a[index] == str_b[index])
    {
        index++;
    }
    return str_a.substr(0 , index);
}

