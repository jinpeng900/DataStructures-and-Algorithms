/*

问题分析： 
    目标是利用三元组实现对稀疏矩阵的转置
        转置后 矩阵B 的行数为转置前 矩阵A 的列数
        转置后 矩阵B 的列数为转置前 矩阵A 的行数
        非零元素个数转置前后均相等

解题思路
    暴力求解
        1.先找到原始三元组表里最小的 j (在进行转置后它会变为最小的)
        2.难点，将原始三元组表里 j 最小的那组数据存入转置后的那个三元组表 ， 随着循环不断进行 ， 转置后的三元组就完成了

*/
#include<bits/stdc++.h>

using namespace std;

struct minitable{
    int i;
    int j;
    int zhi;
    // 表示三元组表里的一个非零元素的行号 ， 列号 ， 值
};

struct table{
    minitable data[100];
    // 三元组的元素的个数
    int hangnum;
    int lienum;
    int num;
    // 行数 ， 列数 ， 非零元素个数
};

table tranpose(table a)
{
    table b;
    b.hangnum = a.lienum;
    b.lienum = a.hangnum;
    b.num = a.num;
    // 这里是b的行数为a的列数 ， b的列数为a的行数 ， 因为矩阵进行了转置 ， 行列数目交换
    // 交换后仍然要保证行数从上到下递减
    int k = 0;

    for (int i = 1 ; i <= a.num ; i++)
    {
        // 第一个循环用于找到原始三元组里列号 j 最小的 (交换后行数i最小放在转置后的矩阵上面)
        int min = 1e9;
        for (int m = 0 ; m < a.num ; m++)
        {
            if (a.data[m].j < min)
            {
                min = a.data[m].j;
                // 朴实无华的暴力
            }
        }

        for (int m = 0 ; m < a.num ; m++){
            if (a.data[m].j == min){
                // 找到最小值 ， 进行转置
                b.data[k].zhi = a.data[m].zhi;
                b.data[k].i = a.data[m].j;
                b.data[k].j = a.data[m].i;
                k++;
                a.data[m].j = 1e9;
                break;
            }
        }
    }
    return b;
}


int main()
{
    table A;
    A.hangnum = 5 , A.lienum = 5 , A.num = 6;
    A.data[0].i = 0 , A.data[0].j = 1 , A.data[0].zhi = 8;
    A.data[1].i = 3 , A.data[1].j = 2 , A.data[1].zhi = 3;
    A.data[2].i = 4 , A.data[2].j = 5 , A.data[2].zhi = 6;
    A.data[3].i = 5 , A.data[3].j = 0 , A.data[3].zhi = 7;
    A.data[4].i = 5 , A.data[4].j = 4 , A.data[4].zhi = 9;
    A.data[5].i = 5 , A.data[5].j = 5 , A.data[5].zhi = 5;

    cout << "转置前的三元组表A为:" << endl;
    for (int m = 0 ; m < A.num ; m++)
    {
        cout << A.data[m].i << " " << A.data[m].j << " " << A.data[m].zhi << endl;
    }

    table B = tranpose(A);

    cout << "转置后的三元组表B为:" << endl;
    for (int m = 0 ; m < A.num ; m++)
    {
        cout << B.data[m].i << " " << B.data[m].j << " " << B.data[m].zhi << endl;
    }
    return 0;
}