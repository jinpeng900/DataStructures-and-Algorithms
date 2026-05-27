# include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool first_row_has_zero = (find(matrix[0].begin(), matrix[0].end(), 0) != matrix[0].end());

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            // 倒着遍历，避免提前把 matrix[i][0] 改成 0，误认为这一行要全部变成 0
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (first_row_has_zero) {
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }
    }
};