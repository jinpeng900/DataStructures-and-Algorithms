# include<bits/stdc++.h>
using namespace std;

int find(vector<int>&g , vector<int>&s){
    int num = 0;
    sort(g.begin() , g.end());
    sort(s.begin() , s.end());

    int m = g.size();
    int n = s.size();
    int i = 0;
    int j = 0;

    while (i < m && j < n){
        if (g[i] <= s[j]){
            i++;
            num++;
        }
        j++;
    }
    return num;
}

int main(){
    vector<int> a = {1 , 2};
    vector<int> b = {1 , 2 , 3};
    cout << find(a , b) << endl;
    return 0;
}