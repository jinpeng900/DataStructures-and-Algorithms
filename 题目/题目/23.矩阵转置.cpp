#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> transpose(const vector<vector<int>>& matrix) 
{
    if (matrix.empty()) return {};
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> r_matrix(cols, vector<int>(rows));
    for (int i = 0 ; i < rows ; i++)
    {
        for (int j = 0 ; j < cols ; j++)
        {
            r_matrix[j][i] = matrix[i][j];
        }
    }
    return r_matrix;
}


int main()
{
    vector<vector<int>> matrix(3, vector<int>(3));
    matrix[0][0] = 2;
    matrix[0][1] = 4;
    matrix[0][2] = -1;
    matrix[1][0] = -10;
    matrix[1][1] = 5;
    matrix[1][2] = 11;
    matrix[2][0] = 18;
    matrix[2][1] = -7;
    matrix[2][2] = 6;

    vector<vector<int>> r_matrix = transpose(matrix);
    for (int i = 0 ; i < 3 ; i++)
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            cout << r_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}