# include<bits/stdc++.h>
using namespace std;

int used[25];
string words[25];
int max_len = 0;
int n;

/*
单词接龙是一个与我们经常玩的成语接龙相类似的游戏，
现在我们已知一组单词 ，且给定一个开头的字母，要求出以这个字母开头的最长的 “龙”
（每个单词最多在 “龙” 中出现两次，如果存在和完全相同，则他们在 “龙” 中一共可以最多出现四次），
在两个单词相连时，其重合的开头字母与结尾字母合为一个字母，例如 beast 和 tree ，如果接成一条龙则变为 beastree 。

*/


void dfs(int index , int current_len){
    max_len = max(max_len , current_len);

    for (int i = 0 ; i < n ; i++){
        if (words[i].front() == words[index].back() && used[i] != 2){
            used[i]++;
            dfs(i , current_len + words[i].length() - 1);
            used[i]--;                  // 回溯
        }
    }


}


int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> words[i];
    }
    
    char c;
    cin >> c;
    for (int i = 0 ; i < n ; i++){
        if (words[i].front() == c){
            used[i]++;
            dfs(i , words[i].length());
            used[i]--;                  // 回溯
        }
    }
    cout << max_len << endl;
    return 0;

}