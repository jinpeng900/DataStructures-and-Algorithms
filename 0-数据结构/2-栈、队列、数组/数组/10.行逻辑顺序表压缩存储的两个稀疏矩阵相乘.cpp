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


// 乘法辅助函数 ， 找到 A[i][j] 与 B[j][i] 的值
int Getval(TSMatrix &A , int i , int j)
{
    int k = 1;      // 矩阵三元组下标
    while (k <= A.num && (A.data[k].i != i || A.data[k].j != j))
    {
        k++;
    }
    if (k <= A.num)
    {
        return A.data[k].data;
    }
    else
    {
        return 0;
    }
}


void MulSMatrix(TSMatrix a , TSMatrix b , TSMatrix &c)
{
    int p = 0;
    int s;
    if (a.m != b.n)
    {
        cout << "两矩阵无法相乘\n" << endl;
        return;
    }

    for (int i = 1 ; i <= a.n ; i++)
    {
        for (int j = 1 ; j <= b.m ; j++)
        {
            s = 0;
            for (int k = 1 ; k <= a.m ; k++)
            {
                s += Getval(a , i , k) * Getval(b , k , j);
            }
            if (s != 0)
            {
                c.data[p + 1].i = i;
                c.data[p + 1].j = j;
                c.data[p + 1].data = s;
                p++;
            }
        }
    }
    c.n = a.m;
    c.m = b.n;
    c.num = p;
}

