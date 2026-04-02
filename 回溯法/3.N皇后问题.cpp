# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    string origin = "";
    int n;

    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        origin = string(n, '.');
        vector<int> pos(n + 1, 0);  
        dfs(1, pos);
        return ans;
    }

    void dfs(int i, vector<int>& pos) {  
        if (i > n) {
            vector<string> str;
            for (int row = 1; row <= n; row++) {
                string cu = origin;
                cu[pos[row] - 1] = 'Q';
                str.push_back(cu);
            }
            ans.push_back(str);
            return;
        }

        for (int j = 1; j <= n; j++) {
            if (check(i, j, pos)) {
                pos[i] = j;
                dfs(i + 1, pos);
                pos[i] = 0;
            }
        }
    }

    bool check(int i, int j, vector<int>& pos) {
        for (int k = 1; k < i; k++) {
            if (pos[k] == j || abs(i - k) == abs(j - pos[k]))
                return false;
        }
        return true;
    }
};