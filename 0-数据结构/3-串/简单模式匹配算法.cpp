#include<bits/stdc++.h>
using namespace std;

// 暴力匹配算法
int Index(string S , string T){
    int  i = 1 , j = 1;
    while(i <= S.size() && j <= T.size()){
        if(S[i] == T[j]){
            i++;
            j++;
        }
        else{
            i = i - j + 2;
            j = 1;
        }
    }
    if(j > T.size()){
        return i - T.size();
    }
    else{
        return 0;
    }
}