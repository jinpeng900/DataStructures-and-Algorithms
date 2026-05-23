# include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int length = nums.size();

    vector<int>L(length , 0);
    vector<int>R(length , 0);

    L[0] = 1;
    for (int i = 1 ; i < length ; i++){
        L[i] = L[i-1] * nums[i-1];
    }

    R[length - 1] = 1;
    for (int i = length - 2 ; i >= 0 ; --i){
        R[i] = R[i+1] * nums[i+1];
    }

}