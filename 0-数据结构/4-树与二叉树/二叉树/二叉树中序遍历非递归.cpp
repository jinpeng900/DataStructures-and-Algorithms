#include<iostream>
#include<stack>

using namespace std;


/*

1. 二叉树为空啥也不做
2. 结点不为空 ， 访问并入栈 ， 接着遍历左子树
3. 结点的左子树为空但是栈不为空 ， 栈顶元素出栈并访问 ， 接着遍历栈顶元素的右子树
4. 栈为空 ， 且结点也为空时结束遍历

*/
typedef struct hlNode
{
    char data;
    struct hlNode * left;
    struct hlNode * right;
}hlNode , *hlTree;


void visit(hlTree T)
{
    cout << T->data << endl;
}


void PreOrder(hlTree T)
{
    stack<hlTree>S;           // 申请一个辅助栈
    hlTree p = T;           // p 为遍历指针
    while (p || !S.empty())         // 栈不为空 或者 p 不为空时循环
    {
        if (p)                                      // 一路向左
        {
            S.push(p);                        
            p = p->left;                           // 左子树不空 , 一直向左走
        }
        else
        {
            hlTree temp = S.top();                 
            visit(temp);
            S.pop();                                // 栈顶元素出栈
            p = temp->right;                        // 向右子树走 ， p 赋值为当前结点的右子树
        }
    }

}


int main()
{
    // create all nodes
    hlTree T = new hlNode();
    hlTree B = new hlNode();
    hlTree C = new hlNode();
    hlTree D = new hlNode();
    hlTree E = new hlNode();
    hlTree F = new hlNode();
    hlTree G = new hlNode();

    // assign data and links to form the tree:
    //        A
    //       / \
    //      B   C
    //     / \   \
    //    D   E   F
    //       /
    //      G

    T->data = 'A';
    T->left = B;
    T->right = C;

    B->data = 'B';
    B->left = D;
    B->right = E;

    D->data = 'D';
    D->left = NULL;
    D->right = NULL;

    E->data = 'E';
    E->left = G;
    E->right = NULL;

    G->data = 'G';
    G->left = NULL;
    G->right = NULL;

    C->data = 'C';
    C->left = NULL;
    C->right = F;

    F->data = 'F';
    F->left = NULL;
    F->right = NULL;

    PreOrder(T);

    system("pause");
    return 0;
}

