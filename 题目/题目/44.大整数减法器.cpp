#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b, ans;
    cin >> a >> b;

    // 先判断绝对值大小，确保始终做“大数减小数”。
    bool negative = false;
    if (a.length() < b.length() || (a.length() == b.length() && a < b)) {
        swap(a, b);
        negative = true;
    }

    int len_a = static_cast<int>(a.length());
    int len_b = static_cast<int>(b.length());

    int i = len_a - 1;
    int j = len_b - 1;

    int borrow = 0;
    while (i >= 0 || j >= 0) {
        int x = (i >= 0) ? (a[i] - '0') : 0;
        int y = (j >= 0) ? (b[j] - '0') : 0;

        int d = x - y - borrow;
        if (d < 0) {
            d += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        ans.push_back(static_cast<char>(d + '0'));

        --i;
        --j;
    }

    while (ans.size() > 1 && ans.back() == '0') {
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());
    if (negative && ans != "0") {
        ans = "-" + ans;
    }

    cout << ans << endl;
    return 0;
}