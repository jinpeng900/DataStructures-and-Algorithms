#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 计算数组 src 中每个元素在 target 数组中能找到的最小差值的最大值
int getMinDiffMax(vector<int>& src, vector<int>& target) {
    int max_min_diff = 0;
    for (int x : src) {
        // 在 target 中寻找第一个 >= x 的位置
        auto it = lower_bound(target.begin(), target.end(), x);
        int current_min = 2e9; // 初始化为一个很大的数
        
        // 检查右侧最接近的数
        if (it != target.end()) {
            current_min = min(current_min, *it - x);
        }
        // 检查左侧最接近的数
        if (it != target.begin()) {
            current_min = min(current_min, x - *(--it));
        }
        
        max_min_diff = max(max_min_diff, current_min);
    }
    return max_min_diff;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, N;
    if (!(cin >> M >> N)) return 0;

    vector<int> A(M), B(N);
    for (int i = 0; i < M; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // 结果是：A 找 B 的最大最小差值 与 B 找 A 的最大最小差值 中的较大者
    int resA = getMinDiffMax(A, B);
    int resB = getMinDiffMax(B, A);

    cout << max(resA, resB) << endl;

    return 0;
}