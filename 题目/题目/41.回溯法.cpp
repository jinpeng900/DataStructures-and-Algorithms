# include<bits/stdc++.h>
using namespace std;

bool check(int i, int j, vector<int>& pos) {
        for (int k = 1; k < i; k++) {
            if (pos[k] == j || abs(i - k) == abs(j - pos[k]))
                return false;
        }
        return true;
}

int ans = 0;
vector<int>pos(9 , 0);           // 标注每一行放的位置

void dfs(int i){
    if (i > 8){
        ans++;
        return;
    }

    if (pos[i] == 0){
        for (int j = 1 ; j <= 8 ; j++){
        if (check(i , j , pos)){
            pos[i] = j;
            dfs(i+1);
            pos[i] = 0;
        }
    }
    }

    else{
        if (check(i , pos[i] , pos)){
            dfs(i+1);
        }
    }
}



int main(){
    for (int i = 1 ; i <= 8 ; i++){
        for (int j = 1 ; j <= 8 ; j++){
            int p;
            cin >> p;
            if (p != 0){
                pos[i] = j;
            }
        }
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}