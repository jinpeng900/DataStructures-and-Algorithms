#include <iostream>
#include <algorithm>
using namespace std;

struct node {
  int p,c;
} a[100005];

int main() {
  int n;
  long long s, sum = 0;
  cin>>n>>s;
  for (int i=1; i<=n; i++)
    cin>>a[i].p>>a[i].c, sum += a[i].p;
  sort(a+1, a+1+n, [](node &n1, node &n2) {
    return n1.c < n2.c;
  });
  
  long long ans = 0, cnt = 0;
  for (int i=1; i<=n; i++) {
    if (sum >= s) {
      ans = a[i].c * s;
      sum -= a[i].p;
      cnt = a[i].c; // or: cnt = a[i].c;
    } else {
      ans += (a[i].c - cnt) * a[i].p;
    }
  }
  cout<<ans<<'\n';
  
  return 0;
}