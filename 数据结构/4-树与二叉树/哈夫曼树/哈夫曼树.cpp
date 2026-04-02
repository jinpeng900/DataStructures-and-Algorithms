#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

// 树结构定义
typedef struct _htNode      // 树的结点
{
    char symbol;
    struct _htNode *left , *right;
}htNode;


typedef struct _htTree      // 树
{
    htNode * root;          // 头结点
}htTree;



// 队列的结构定义
#define TYPE htNode*
#define MAX_SZ 256


typedef struct _pQueueNode      // 队列的成分由解码字符与有优先级和指针组成
{
    TYPE val;       // 所有被加入到对队列中的结点都是叶子结点
    unsigned int priority;      // 优先级 ， 即字符频率
    struct _pQueueNode *next;
}pQueueNode;


typedef struct _pQueue
{
    pQueueNode * first;     // 队列头指针 ， 这里指向第一个 pQueueNode
    unsigned int size;
    /*
        当最后队列只有一个元素时 ， 这个数据就是 Huffman树 的根节点
        所以这个 size 帮我们判断树的构建进度
    */
}pQueue;



typedef struct _hlNode      // 表的结点
{
    char symbol;
    char *code;
    struct _hlNode *next;
}hlNode;



typedef struct _hltable         // 表
{
    hlNode *first;
    hlNode *last;
}hlTable;



// 队列的初始化 ， 初始时 ， 队列中没有节点 ， first 指向空 , size 设为 0
// queue 指针指向队列 ， 所以传入的是 *queue 
void initPQueue(pQueue **queue)
{
    (*queue) = (pQueue*)malloc(sizeof(pQueue));
    (*queue)->first = NULL;
    (*queue)->size = 0;
}



void addQueue(pQueue **queue , TYPE val , unsigned int priority)
{
    if ((*queue)->size == MAX_SZ)
    {
        cout << "队列已满!" << endl;
        return;
    }
    // 生成一个结点
    pQueueNode * pNode = (pQueueNode *)malloc(sizeof(pQueueNode));
    pNode->val = val;
    pNode->priority = priority;

    if ( (*queue)->size == 0 || priority <= (*queue)->first->priority || (*queue)->first == NULL)        // 如果队列为空或者插入元素优先级小于队列第一个 ， 直接插入
    {
        // 注意：由于当队列为空时 ， 结点未初始化
        pNode->next = (*queue)->first;
        (*queue)->first = pNode;
        (*queue)->size++;
        return;
    }
    else
    {
        pQueueNode * iterator = (*queue)->first;
        // 要么插入到队列之中 ， 要么插入到最后
        while (iterator->next != NULL)
        {
            // 迭代
            if (priority <= iterator->next->priority)
            {
                pNode->next = iterator->next;
                iterator->next = pNode;
                (*queue)->size++;
                return;
            }
            iterator = iterator->next;
        }
        if (iterator->next == NULL)
        {
            pNode->next = NULL;
            iterator->next = pNode;
            (*queue)->size++;
            return;
        }
    }
}



// 出队函数
// 从队列中取出叶子结点（用于建树）
// 选择在外部判断 size , 而不在函数内 ， 故在外部一定要检查 *pQueue->size
TYPE getPQueue(pQueue **pQueue)
{
    TYPE leafVal;       // 用 leafVal 返回队列中的值作为叶子结点
    // 每次移动游标然后free即可
    leafVal = (*pQueue)->first->val;
    pQueueNode * old = (*pQueue)->first;
    (*pQueue)->first = (*pQueue)->first->next;
    (*pQueue)->size--;
    free(old);
    return leafVal;
}



// 构建 Huffman 树
/*

    1.获取字符频率
    2.将字符和字符频率入队
    3.从队列中连续取出两个叶子结点构建哈夫曼树 ， 知道队列中无元素（队列中的最后一个元素是根结点）

*/
void buildTree(htTree *huffmanTree , char * encodeString)
{
    // 1.首先 ， 获取字符的频率
    // 我们所有的编码都可以利用 ASCII码 表示 ， 而 ASCII码 由 256 个 ， 所以我们需要一个大小为 256(MAX_SZ) 的整型数组
    int frequency[MAX_SZ] = {0};        // 初始化为0

    // 然后获取字符串中每一个字符的频率---从字符串的开头 ， 到字符串的结尾(\0)
    for (int i = 0 ; encodeString[i] != '\0' ; i++)
    {
        frequency[(unsigned int)encodeString[i]]++;
    }

    // 2.创建队列
    pQueue *huffmanQueue;
    initPQueue(&huffmanQueue);
    // 遍历数组 ， 从中取出所有非零的数 （如果没出现 ， 没必要为其建树 、 编码）
    // 由于我们已经写好了 addQueue 函数 ， 只需要在遍历时调用该函数即可
    for (int i = 0 ; i < MAX_SZ ; i++)
    {
        // 队列中的元素为 htNode , 包含多代表的字符与左右孩子
        // 所有被加入到队列的结点都是 Huffman 的叶子结点
        // 创建结点并入队
        if (frequency[i])
        {
            htNode * leafNode = (htNode*)malloc(sizeof(htNode));
            leafNode->symbol = (char)i;
            leafNode->left = leafNode->right = NULL;
            addQueue(&huffmanQueue , leafNode , frequency[i]);
        }
    }



    // 测试队列的创建是否有问题
    for (pQueueNode * testPrintQ = huffmanQueue->first ; testPrintQ ; testPrintQ = testPrintQ->next)
    {
        cout << "值为" << testPrintQ->val->symbol << "的优先级为" << testPrintQ->priority << endl;
    }



    // 3. 重头戏之建树
    // 只要队列中还剩下结点 ， 就建树 ， 不过最后一个结点是根结点
    while(huffmanQueue->size > 1)
    {
        int priority = huffmanQueue->first->priority + huffmanQueue->first->next->priority;
        // 生成中间结点作为头两个队列结点的双亲
        htNode *inNode = (htNode*)malloc(sizeof(htNode));
        inNode->left = getPQueue(&huffmanQueue);
        inNode->right = getPQueue(&huffmanQueue);
        // 取出队列中的两个元素 ， 权重
        addQueue(&huffmanQueue , inNode , priority);        // 入队
    }
    huffmanTree->root = getPQueue(&huffmanQueue);
    
}



// 遍历树 ， 输出叶子结点的字符
void testSymbol(htNode *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->symbol << endl;
    }
    else
    {
        testSymbol(root->left);
        testSymbol(root->right);
    }
}



// 遇到叶子结点则当前遍历完毕 ， 继续下一次遍历
// 我们用 char code[256] 保存遍历的编码 ， 但是要把结果保存在 hlNode 的 code 之中
void traverseTree(htNode *root , hlTable **codetable , int k , char code[256])
{
    if (root->left == NULL && root->right == NULL)      // 如果是叶子
    {
        code[k] = '\0';       // 结束字符串
        hlNode *aux = (hlNode*)malloc(sizeof(hlNode));
        aux->code = (char *)malloc(sizeof(char) * (strlen(code)+1) );
        strcpy(aux->code , code);
        aux->symbol = root->symbol;
        aux->next = NULL;

        if ((*codetable)->first == NULL)
        {
            (*codetable)->first = aux;
            (*codetable)->last = aux;
        }

        else
        {
            (*codetable)->last->next = aux;
            (*codetable)->last = aux;
        }
    }

    // 0 , 1 编码部分、
    if (root->left != NULL)
    {
        code[k] = '0';
        traverseTree(root->left , codetable , k+1 , code);
        // k+1 , 使得可持续向下迭代 ， 为其编码 ， 下同
    }

    if(root->right != NULL)
    {
        code[k] = '1';
        traverseTree(root->right , codetable , k+1 , code);
    }

}



// 建表
hlTable *buildTable(htTree *huffmanTree)
{
    // 表的初始化
    hlTable *table = (hlTable *)malloc(sizeof(hlTable));
    table->first = NULL;
    table->last = NULL;
    
    char code[256];
    int k = 0;      // 没有 k 的话 ， 不知道编码到第一个数字了

    traverseTree(huffmanTree->root , &table , k , code);     // 遍历树 ， 完善表
    return table;
}


int main()
{
    // 测试队列
    char str[] = "CAS;CAT;SAT;AT";

    htTree huffmanTree;
    buildTree(&huffmanTree , str);
    hlTable *codetable = buildTable(&huffmanTree);
    string ans[MAX_SZ];
    string coding;
    for (hlNode * node = codetable->first ; node ; node = node->next)
    {
        ans[(int)node->symbol] = node->code;
    }
    for (size_t i = 0 ; i < strlen(str) ; i++)
    {
        string s = ans[(int)str[i]];
        coding += s;
    }
    cout << coding << endl;
    system("pause");
    return 0;
}



