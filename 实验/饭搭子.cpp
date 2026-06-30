#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , W;
    cin >> n >> W;

    vector<int>path(n , 0);

    for (int i = 0 ; i < n ; i++){
        cin >> path[i];
    }
    sort(path.begin() , path.end());

    int i = 0 , j = n - 1;
    int num = n;

    while (i < j){
        if (path[i] + path[j] > W){
            j--;
        }
        else{
            num--;
            i++;
            j--;
        }
    }

    cout << num << endl;
    return 0;

}