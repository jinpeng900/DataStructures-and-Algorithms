# include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> & matrix , int target){
    int m = matrix.size();
    int n = matrix[0].size();

    int x = 0;
    int y = n-1;

    while (x < m && y > 0){
        if (matrix[x][y] > target){
            y--;
        }
        
        else if (matrix[x][y] < target){
            x++;
        } 

        else{
            return true;
        }
    }

    return false;
}