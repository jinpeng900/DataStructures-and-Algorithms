# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string tmp;
    vector<string> res;
    vector<string> board={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void DFS(int pos,string digits){
        if(pos==digits.size()){
            res.push_back(tmp);
            return;
        }
        int num=digits[pos]-'0';
        for(int i=0;i<board[num].size();i++){
            tmp.push_back(board[num][i]);
            DFS(pos+1,digits);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return res;
        DFS(0,digits);
        return res;
    }
};