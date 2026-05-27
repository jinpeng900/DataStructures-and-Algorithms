# include<bits/stdc++.h>
using namespace std;

/*
    矩阵转置 : matrix[i][j] <--> matrix[j][i]
    矩阵水平镜像 : matrix[i][j] <--> matrix[i][n-1-j]
    矩阵垂直镜像 : matrix[i][j] <--> matrix[m-1-i][j]
    矩阵顺时针旋转 90 度 : 垂直镜像 + 转置
    矩阵顺时针旋转 180 度 : 水平镜像 + 垂直镜像
    矩阵逆时针旋转 90 度 : 水平镜像 + 转置
*/


void rotate(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    // 垂直镜像
    for (int i = 0 ; i < m / 2 ; ++i){
        for (int j = 0 ; j < n ; ++j){
            int p  = matrix[i][j];
            matrix[i][j] = matrix[m - 1 - i][j];
            matrix[m - 1 - i][j] = p;
        }
    }

    // 转置
    for (int i = 0 ; i < m ; ++i){
        for (int j = i ; j < n ; ++j){
            int p = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = p;
        }
    }

}