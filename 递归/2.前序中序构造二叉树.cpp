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


TreeNode* helper(vector<int>& preorder, vector<int>& inorder, 
                int start_pre, int end_pre, int start_in, int end_in) {
    
    // 1. 终止条件：只要任意一个区间为空，就返回空
    if (start_pre >= end_pre || start_in >= end_in) {
        return nullptr;
    }

    // 2. 根节点永远是当前前序遍历区间的第一个元素
    int root_val = preorder[start_pre];
    TreeNode* root = new TreeNode(root_val);

    // 3. 在中序遍历中找到根节点的位置 pos
    int pos = start_in;
    while (pos < end_in && inorder[pos] != root_val) {
        pos++;
    }

    // 4. 递归关键点：利用 pos 直接划分区间
    
    // 【左子树】
    // 中序：从 start_in 到 pos（不含 pos）
    // 前序：从 start_pre + 1 开始，结尾是 (start_pre + 1 + 左子树长度)
    // 注意：左子树长度 = pos - start_in
    root->left = helper(preorder, inorder, 
                        start_pre + 1, start_pre + 1 + (pos - start_in), 
                        start_in, pos);

    // 【右子树】
    // 中序：从 pos + 1 开始到 end_in（跳过根节点 pos）
    // 前序：紧接左子树结尾开始，到 end_pre 结束
    root->right = helper(preorder, inorder, 
                         start_pre + 1 + (pos - start_in), end_pre, 
                         pos + 1, end_in);

    return root;
}

