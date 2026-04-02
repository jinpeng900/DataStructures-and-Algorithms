#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, x, y, h;
    cin >> n >> k >> x >> y >> h;
    x--; y--; // 转为 0-based 下标

    /*
        grid 含义：
        0  ：普通格子
        -1 ：被将军控制的格子（进入会扣血）
        -2 ：将军所在位置（不能进入）
    */
    vector<vector<int>> grid(n, vector<int>(n, 0));

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    // ===== 标记将军和控制区 =====
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        grid[a][b] = -2; // 将军位置

        // 四个方向标记控制区
        for (int d = 0; d < 4; d++) {
            int nx = a + dx[d];
            int ny = b + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (grid[nx][ny] != -2) { // 避免覆盖其他将军
                    grid[nx][ny] = -1;
                }
            }
        }
    }

    /*
        vis[i][j]：
        表示“到达 (i,j) 时，能拥有的最大血量”
        
        为什么要这个？
        因为：
        同一个点，用更高血量到达，可以走更远！
    */
    vector<vector<int>> vis(n, vector<int>(n, -1));

    /*
        used[i][j]：
        表示这个格子是否已经被统计过（计入答案）
        
        防止重复计数！
    */
    vector<vector<bool>> used(n, vector<bool>(n, false));

    // BFS 队列：((x, y), 当前剩余血量)
    queue<pair<pair<int,int>, int>> q;

    // 起点入队
    q.push({{x, y}, h});
    vis[x][y] = h;

    int ans = 0; // 可占领格子数量

    // ===== BFS 开始 =====
    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        int i = cur.first.first;
        int j = cur.first.second;
        int hp = cur.second;

        /*
            ⭐ 关键点1：只统计一次
            因为一个点可能被多次访问（血量更优）
        */
        if (!used[i][j]) {
            used[i][j] = true;
            ans++;
        }

        // 四个方向扩展
        for (int d = 0; d < 4; d++) {
            int nx = i + dx[d];
            int ny = j + dy[d];

            // 越界
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            // 不能走到将军
            if (grid[nx][ny] == -2) continue;

            int new_hp = hp;

            // 如果是控制区，扣血
            if (grid[nx][ny] == -1) new_hp--;

            // 血量为 0 或以下，不能继续
            if (new_hp <= 0) continue;

            /*
                ⭐ 关键点2：只在“更优”时更新
                
                如果这次到达该点血量更多，才值得继续走
            */
            if (new_hp > vis[nx][ny]) {
                vis[nx][ny] = new_hp;
                q.push({{nx, ny}, new_hp});
            }
        }
    }

    cout << ans << '\n';
    return 0;
}