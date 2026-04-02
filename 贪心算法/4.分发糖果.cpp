// 既然评分高得更多糖果这个规则涉及到左右两个邻居，
// 那我们就先只考虑左邻居，再只考虑右邻居，最后取两者中的最大值。


# include<bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings){
    int n = ratings.size();
    int res = 0;
    vector<int> left(n);
    vector<int> right(n);

    for (int i = 0 ; i < n ; i++){
        if (i > 0 && ratings[i] > ratings[i-1]){
            left[i] = left[i - 1] + 1;
        }
        else{
            left[i] = 1;
        }
    }

    for (int i = n-1 ; i >= 0; i--){
        if (i < n-1 && ratings[i] > ratings[i+1]){
            right[i] = right[i+1] + 1;
        }
        else{
            right[i] = 1;
        }
        res += max(left[i] , right[i]);
    }
    return res;


}