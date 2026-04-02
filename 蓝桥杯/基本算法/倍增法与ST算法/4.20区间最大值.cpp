#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int query(int l , int r){
  int j = (int)log2(r - l + 1);
  return max(dp[l][j] , dp[r - (1<<j) + 1][j]);
}

int main()
{
  // 请在此输入您的代码
  int n , m;
  cin >> n >> m;
  int arr[n+1];
  for(int i = 1 ; i <= n ; i++){
    cin >> arr[i];
  }
  dp = vector<vector<int>>(n+1 , vector<int>((int)log2(n)+3 , 0));
  for (int i = 1 ; i <= n ; i++) dp[i][0] = arr[i];
  for (int j = 1 ; j <= log2(n) ; j++){
    for (int i = 1 ; i + (1 << (j)) - 1 <= n ; i++){
      dp[i][j] = max(dp[i][j-1] , dp[i + (1<<(j-1))][j-1]);
    }
  }
  while(m--){
    int l , r;
    cin >> l >> r;
    cout << query(l , r) << endl;
  }
  return 0;
