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

bool hasPathSum(TreeNode* root , int targetSum){
    if (root == nullptr){
        return false;
    }
    if (root->left == nullptr && root->right == nullptr){
        if (root->val == targetSum){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return hasPathSum(root->left , targetSum - root->val) || hasPathSum(root->right , targetSum - root->val);
    }
}

