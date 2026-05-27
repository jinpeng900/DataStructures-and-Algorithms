# include<bits/stdc++.h>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};
    
    int n = matrix.size(), m = matrix[0].size();
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    vector<int> ans;
    
    while (ans.size() < n * m) {
        // 向右：遍历上边界
        for (int i = left; i <= right && ans.size() < n * m; ++i) 
            ans.push_back(matrix[top][i]);
        top++;
        
        // 向下：遍历右边界
        for (int i = top; i <= bottom && ans.size() < n * m; ++i) 
            ans.push_back(matrix[i][right]);
        right--;
        
        // 向左：遍历下边界
        for (int i = right; i >= left && ans.size() < n * m; --i) 
            ans.push_back(matrix[bottom][i]);
        bottom--;
        
        // 向上：遍历左边界
        for (int i = bottom; i >= top && ans.size() < n * m; --i) 
            ans.push_back(matrix[i][left]);
        left++;
    }
    return ans;
}