#include<bits\stdc++.h>
#define number 10
using namespace std;


typedef struct{
    int i , j;
    int data;
}triple;


typedef struct{
    triple data[number];
    int n , m , num;
}TSMatrix;

TSMatrix fastTransposeMatrix(TSMatrix M , TSMatrix T)
{
    // 第一步 ， 行和列置换
    T.m = M.n;
    T.n = M.m;
    T.num = M.num;

    if (T.num)
    {
        // 计算 array 数组 ， 记录一列中非零元素个数
        int array[number];
        for (int i = 1 ; i <= M.num ; i++)
        {
            array[i] = 0;
        }
        for (int i = 0 ; i < M.num ; i++)
        {
            int j = M.data[i].j;
            array[j]++;
        }

        // 创建并初始化 cpot 数组
        int copt[T.m+1];
        copt[1] = 1;        // 第一列中第一个非零元素的位置默认为 1
        for (int col = 2 ; col <= M.m ; col++)
        {
            copt[col] = copt[col - 1] + array[col - 1];
        }
        // 遍历一次即可实现三元组表的转置
        for (int p = 0 ; p < M.num ; p++)
        {
            // 提取当前三元组的列数
            int col = M.data[p].j;
            // 根据列数和 copt 数组 ， 找到当前元素需要存放的位置
            int q = copt[col];
            T.data[q-1].i = M.data[p].j;
            T.data[q-1].j = M.data[p].i;
            T.data[q-1].data = M.data[p].data;
            copt[col]++;
        }
    }
    return T;
}


int main()
{
    TSMatrix M;
    M.m = 2;
    M.n = 3;
    M.num = 3;

    M.data[0].i = 1;
    M.data[0].j = 2;
    M.data[0].data = 1;
    
    M.data[1].i = 2;
    M.data[1].j = 2;
    M.data[1].data = 3;

    M.data[2].i = 3;
    M.data[2].j = 1;
    M.data[2].data = 6;

    TSMatrix T;
    T = fastTransposeMatrix(M , T);
    cout << "转置矩阵三元组表为:" << endl;
    for (int i = 0 ; i < T.num ; i++){
        cout << T.data[i].i << " " << T.data[i].j << " " << T.data[i].data << endl;
    }
    return 0;
}