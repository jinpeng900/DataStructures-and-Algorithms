#include<iostream>
using namespace std;

#define TElemType char

typedef struct BITNode
{
    TElemType data;
    struct BITNode * left;
    struct BITNode * right;
}BITNode , *BiTree;


int Depth(BiTree T)
{
    if (T == nullptr)
    {
        return 0;
    }
    int ldepth = Depth(T->left);
    int rdepth = Depth(T->right);
    return (ldepth > rdepth ? ldepth : rdepth) + 1;
}


int Nodes(BiTree T)
{
    if (T == nullptr)
    {
        return 0;
    }
    int lNodes = Nodes(T->left);
    int rNodes = Nodes(T->right);
    return lNodes+rNodes+1;
}


int main()
{
    // create all nodes
    BiTree T = new BITNode();
    BiTree B = new BITNode();
    BiTree C = new BITNode();
    BiTree D = new BITNode();
    BiTree E = new BITNode();
    BiTree F = new BITNode();
    BiTree G = new BITNode();
    
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
    D->left = nullptr;
    D->right = nullptr;

    E->data = 'E';
    E->left = G;
    E->right = nullptr;

    G->data = 'G';
    G->left = nullptr;
    G->right = nullptr;

    C->data = 'C';
    C->left = nullptr;
    C->right = F;

    F->data = 'F';
    F->left = nullptr;
    F->right = nullptr;

    int dep = Depth(T);
    int num = Nodes(T);
    cout <<  num << endl;
    system("pause");
    return 0;

}