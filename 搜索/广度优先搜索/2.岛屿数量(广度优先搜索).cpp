#  include<bits/stdc++.h>
using namespace std;

// 广度优先搜索
/*

    为了求出岛屿的数量 , 我们可以扫描整个二维网格 . 如果一个位置为 1 , 则将其加入到队列中 , 开始进行广度优先搜索 . 在广度优先搜索的
过程中 , 每个搜索到的 1 都会被重新标记为 0 . 

*/

int numIslands(vector<vector<char>>& grid){
    int ans = 0;

    int nr = grid.size();
    if (nr == 0) return 0;
    int nc = grid[0].size();

    int dx[4] = {0 , 0 , 1 , -1};
    int dy[4] = {1 , -1 , 0 , 0};

    for (int i = 0 ; i < nr ; i++){
        for (int j = 0 ; j < nc ; j++){
            if (grid[i][j] == '1'){
                ans++;
                queue<pair<int , int>> q;
                q.push({i , j});
                while (!q.empty()){
                    auto& p = q.front();
                    q.pop();
                    for (int t = 0 ; t < 4 ; t++){
                        int nx = p.first + dx[t];
                        int ny = p.second + dy[t];
                        if (nx >= 0 && nx < nr && ny >= 0 && ny < nc && grid[nx][ny] == '1'){
                            q.push({nx , ny});
                            grid[nx][ny] = '0';
                        }
                    }
                }
            }
        }
    }
    return ans;
}


int main(){
    vector<vector<char>> grid = {
  {'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','1'}
    };
  cout << numIslands(grid) << endl;
  return 0;

}