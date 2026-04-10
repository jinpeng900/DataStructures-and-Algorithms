#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int minDepth(TreeNode* root) {
    queue<pair<TreeNode* , int>> path;

    if (root == nullptr){
        return 0;
    }
    
    path.push({root , 1});

    while (true)
    {
        auto& it = path.front();
        path.pop();
        TreeNode * p = it.first;
        int s = it.second;
        if (p->left == nullptr && p->right == nullptr){
            return s;
        }
        path.push({p->left , s+1});
        path.push({p->right , s+1});
    }
    
    
}