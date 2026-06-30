#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>path(n  ,0 );
    for (int i = 0 ; i < n ; i++){
        cin >> path[i];
    }

    int jishu = 0;
    int oushu = 0;

    for (int i = 0 ; i < n  ; i++){
        if (path[i] % 2 == 0){
            oushu = jishu + 1;
        }
        else{
            jishu = oushu + 1;
        }
    }
    cout << max(jishu , oushu) << endl;
    return 0;
}