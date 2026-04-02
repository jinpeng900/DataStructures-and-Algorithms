#include<iostream>
#include<stack>

using namespace std;


/*

1. 二叉树为空啥也不做
2. 结点不为空 ， 入栈并设立标志 tag = 0 , 并随后遍历左子树
3. 结点为空 ， 则判断栈是否为空 ， 为空则遍历结束 ， 不为空则分为两种情况
            1. tag = 1 （说明栈顶元素的左右子树已经遍历完） ， 出栈并访问栈顶元素
            2. 栈顶标志 tag , 若 tag = 0 (说明栈顶元素的右子树还未遍历) , 则重新设置标志 tag = 1 (此时还在栈中) ， 并遍历栈顶元素的右子树(此过程相当于上面的第一次出栈 ， 遍历右子树 ， 紧接着入栈 ， 故重新标志起到了说明右子树已经访问过这个作用)
            
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



void PostOrder(hlTree T)
{
    if (T == NULL)
    {
        return;
    }
    stack<hlTree>S;
    hlTree p = T;
    hlTree pre = NULL;
    S.push(p);
    while (!S.empty())
    {
        p = S.top();
        if ((p->left == NULL && p->right == NULL) || ((pre == p->left || pre == p->right) && pre != NULL))
        {
            visit(p);
            S.pop();
            pre = p;
        }
        else
        {
            if (p->right != NULL)
            {
                S.push(p->right);
            }
            if (p->left != NULL)
            {
                S.push(p->left);
            }
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

    PostOrder(T);

    system("pause");
    return 0;
}

