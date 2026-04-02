#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;  //谁组合大谁在前
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end(), cmp); 

    string ans;
    for (auto s : v) ans += s;

    if (ans[0] == '0') cout << 0;
    else cout << ans;
}