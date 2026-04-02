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
    int result = -1; // 成员变量，用于存最终答案
    int count = 0;   // 成员变量，作为全局计数器

    void dfs(TreeNode* node, int k) {
        // 1. 递归终止条件：节点为空，或者已经找到了答案（早停）
        if (!node || result != -1) return;

        // 2. 【左】递归左子树：去寻找更小的值
        dfs(node->left, k);

        // 3. 【根】处理当前节点：这是从小到大数数的时刻
        count++; 
        if (count == k) {
            result = node->val;
            return; // 找到了，开始向上返回
        }

        // 4. 【右】递归右子树：如果左边和中间都没到 k，就去右边找
        dfs(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        // 重置状态（防止多次调用产生干扰）
        result = -1;
        count = 0;
        
        dfs(root, k);
        return result;
    }
};