# include<bits/stdc++.h>
using namespace std;

int targ(vector<int> & heights){
    int n = heights.size();
    int ans = 0;
    int left = 0;
    int right = n-1;
    int leftmax = 0;
    int rightmax = 0;

    while (left < right){
        leftmax = max(leftmax , heights[left]);
        rightmax = max(rightmax , heights[right]);

        if (leftmax < rightmax){
            ans += leftmax - heights[left];
            ++left;
        }

        else{
            ans += rightmax - heights[right];
            --right;
        }
    }
    return ans;


}