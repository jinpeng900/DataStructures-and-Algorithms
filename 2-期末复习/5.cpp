#include<bits/stdc++.h>
using namespace std;


int main(){
    int n , m;
    cin >> n >> m;

    int dx[4] = {-1 , 0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};

    vector<vector<int>> path(n , vector<int>(m , 0));
    vector<vector<bool>> visited(n , vector<bool>(m , false));
    queue<tuple<int , int , int>> q;

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            cin >> path[i][j];
        }
    }

    int ans = 0;
    int a , b , c , d;
    cin >> a >> b >> c >> d;

    visited[a][b] = true;
    q.push({a , b , ans});

    while (!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int ans = get<2>(q.front());
        q.pop();

        if (x == c && y == d){
            cout << ans << endl;
            return 0;
        }

        for (int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && path[nx][ny] == 0){
                visited[nx][ny] = true;
                q.push({nx , ny , ans + 1});
            }
    }
    return 0;


}