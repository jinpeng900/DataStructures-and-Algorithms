#include<bits/stdc++.h>
using namespace std;


string dfs(string pre , string in){
    if (pre.empty()){
        return "";
    }
    char c = pre[0];
    int k = in.find(c);

    return dfs(pre.substr(1 , k) , in.substr(0 , k)) + dfs(pre.substr(k+1) , in.substr(k+1)) + c;
}