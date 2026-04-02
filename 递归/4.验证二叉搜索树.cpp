# include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x , TreeNode * left , TreeNode * right) : val(x) , left(left) , right(right) {}
};

class Solution {
public:
    vector<int> res;

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        res.push_back(root->val); // 按升序存入数组
        dfs(root->right);
    }

    bool isValidBST(TreeNode* root) {
        res.clear(); // 清空旧数据
        dfs(root);
        
        // 检查数组是否严格递增
        for (int i = 1; i < res.size(); i++) {
            if (res[i] <= res[i-1]) {
                return false;
            }
        }
        return true;
    }
};