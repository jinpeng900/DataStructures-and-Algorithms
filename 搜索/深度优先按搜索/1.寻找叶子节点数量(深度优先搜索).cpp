# include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> adj[N];
int leaf_num = 0;

void dfs(int u , int fu){
    bool is_leaf = true;
    for (int v : adj[u]){
        if (v == fu) continue;
        is_leaf = false;
        dfs(v , u);
    }
    if (is_leaf && u != 1) leaf_num++;
}

int main(){
    int n;
    cin >> n;
    for (int i = 1 ; i < n ; i++){
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1 , -1);
    cout << leaf_num << endl;
    return 0;
}