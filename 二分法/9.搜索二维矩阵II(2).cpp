# include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> & matrix , int target){
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0 ; i < m ; ++i){
        auto low = lower_bound(matrix[i].begin() , matrix[i].end() , target);
        if (low != matrix[i].end() && *low == target){
            return true;
        }
    }
    return false;
}