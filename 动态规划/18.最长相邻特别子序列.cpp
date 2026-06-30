#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 优化 IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n) || n == 0) {
        cout << 0 << endl;
        return 0;
    }

    // last_odd: 以奇数结尾的最长子序列长度
    // last_even: 以偶数结尾的最长子序列长度
    int last_odd = 0;
    int last_even = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        if (abs(x) % 2 != 0) {
            // 当前是奇数，它可以接在之前的偶数序列后面
            last_odd = last_even + 1;
        } else {
            // 当前是偶数，它可以接在之前的奇数序列后面
            last_even = last_odd + 1;
        }
    }

    cout << max(last_odd, last_even) << endl;
    return 0;
}