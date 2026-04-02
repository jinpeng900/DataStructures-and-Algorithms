# include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            int temp;
            cin >> temp;
            adj[i].push_back(temp);
        }
    }
    int startX , startY , targetX , targetY;
    cin >> startX >> startY;
    cin >> targetX >> targetY;
    startX-- , startY-- , targetX-- , targetY--;

    if (adj[startX][startY] != 0 || adj[targetX][targetY] != 0){
        cout << -1 << endl;
        return 0;
    }

    vector<vector<bool>> vis(n , vector<bool>(m , false));
    queue<tuple<int , int , int >> q;
    q.push({startX , startY , 0});
    vis[startX][startY] = true;

    int dx[4] = {0 , 0 , 1 , -1};
    int dy[4] = {1 , -1 , 0 , 0};


    while (!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int steps = get<2>(q.front());
        q.pop();
        if (x == targetX && y == targetY){
            cout << steps << endl;
            return 0;
        }

        for (int i = 0 ; i < 4 ; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(newx >= 0 && newx < n && newy >= 0 && newy < m && !vis[newx][newy] && adj[newx][newy] == 0){
                vis[newx][newy] = true;
                q.push({newx , newy , steps + 1});
            }
        }
    }
    cout << -1 << endl;




    return 0;
}