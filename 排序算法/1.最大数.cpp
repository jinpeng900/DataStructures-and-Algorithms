#include<bits/stdc++.h>
using namespace std;

bool temp(int , int);

string largestNumber(vector<int>& nums){
    string ans = "";
    sort(nums.begin() , nums.end() , temp);
    for (int i = 0 ; i < nums.size() ; i++){
        ans += to_string(nums[i]);
    }
    return ans;
}


bool temp(int a , int b){
    string a1 = to_string(a);
    string b1 = to_string(b);
    return a1+b1 > b1+a1;
}


int main(){
    vector<int> p = {3 , 30 , 34 , 5 , 9};
    cout << largestNumber(p) << endl;
    return 0;
}