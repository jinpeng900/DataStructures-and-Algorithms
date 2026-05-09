# include<bits/stdc++.h>
using namespace std;

int targ(vector<int>& heights){
    int n = heights.size();
    int ans = 0;

    vector<int> leftmax(n);
    leftmax[0] = heights[0];
    for (int i = 1 ; i < n ; i++){
        leftmax[i] = max(leftmax[i-1] , heights[i]);
    }

    vector<int> rightmax(n);
    rightmax[n-1] = heights[n-1];
    for (int i = n-2 ; i >= 0 ; --i){
        rightmax[i] = max(rightmax[i+1] , heights[i]);
    }

    for (int i = 0 ; i < n ; i++){
        ans += min(leftmax[i] , rightmax[i]) - heights[i];
    }

    return ans;
}