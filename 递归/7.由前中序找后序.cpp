# include <bits/stdc++.h>
using namespace std;

string dfs(string pre , string in){
  if (pre.empty()) return "";

  char temp = pre[0];
  int k = in.find(temp);

  return dfs(pre.substr(1 , k) , in.substr(0 , k)) + dfs(pre.substr(k + 1) , in.substr(k + 1)) + temp;
}

int main(){
  string in , pre;
  cin >> in >> pre;
  cout << dfs(pre , in) << endl;
  return 0;
 }
