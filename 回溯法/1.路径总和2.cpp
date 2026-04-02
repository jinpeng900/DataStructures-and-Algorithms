# include<bits/stdc++.h>
using namespace std;
// 深度优先搜索 + 回溯法 ， 注意 targetSum 是引用的 ， 也需要在最后进行回溯处理。
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x , TreeNode * left , TreeNode * right) : val(x) , left(left) , right(right) {}
};

vector<vector<int>> ans;
vector<int>path;

void dfs(TreeNode * root , int& targetSum){
        if (root == nullptr){
        return;
    }

    path.emplace_back(root->val);
    targetSum -= root->val;
    if (root ->left == nullptr && root -> right == nullptr &&  targetSum == 0){
        ans.push_back(path);
    }
    dfs(root -> left , targetSum);
    dfs(root -> right , targetSum);

    // 回溯
    targetSum += root->val;
    path.pop_back();

}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root , targetSum);
        return ans;
}