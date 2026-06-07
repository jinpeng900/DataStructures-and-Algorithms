# include<bits/stdc++.h>
using namespace std;


int main(){
    int n , T;
    cin >> n >> T;
    vector<int> path;

    for (int i = 0 ; i < n ; i++){
        int a , b;
        cin >> a >> b;
        if (a <= T){
            path.push_back(b);
        }
    }

    sort(path.begin() , path.end());

    int ans = 0;
    int time = 120;

    for (int i = 0 ; i < path.size() ; i++){
        if (time >= path[i]){
            ans++;
            time -= path[i];
        }
        else break;
    }

    cout << ans << endl;

}