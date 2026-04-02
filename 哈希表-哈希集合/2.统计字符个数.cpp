# include<bits/stdc++.h>
using namespace std;

int main(){

    int n , q;
    cin >> n >> q;

    string str;
    cin >> str;

    unordered_map<char , int> path;

    for (int i = 0 ; i < n ; i++){
        path[str[i]]++;
    }

    while (q--){
        char c;
        cin >> c;
        cout << path[c] << endl;
    }

    return 0;
}