# include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums , int k){
    deque<int> dq;

    for (int i = 0 ; i < nums.size() ; ++i){
        dq.push_back(nums[i]);
    }

    for (int i = 0 ; i < k ; ++i){
        int num = dq.back();
        dq.pop_back();
        dq.push_front(num);
    }

    for (int i = 0 ; i < nums.size() ; ++i){
        int num = dq.front();
        dq.pop_front();
        nums[i] = num;
    }
}