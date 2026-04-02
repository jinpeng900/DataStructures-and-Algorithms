# include<bits/stdc++.h>
using namespace std;


bool check(int i , int j , vector<int>& pos) {
    for(int k = 1 ; k < i ; k++){
        if (pos[k] == j || abs(i - k) == abs(j - pos[k])){
            return false;
        }
    }
    return true;
}

int ans =  0;

void dfs(int i , int& n , vector<int>& pos){
    if (i > n){
        ans++;
        return;
    }

    for (int j = 1 ; j <= n ; j++){
        if (check(i , j , pos)){
            pos[i] = j;
            dfs(i+1 , n , pos);
            pos[i] = 0;
        }
    }
    
}

int main(){
    int n;
    cin >> n;
    vector<int> pos(n+1 , 0);
    dfs(1 , n , pos);
    cout << ans << endl;
    return 0;
}