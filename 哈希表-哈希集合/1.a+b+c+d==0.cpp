#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // 加速输入输出，防止在大数据量下超时
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    while (N--) {
        int T;
        cin >> T;
        vector<int> A(T), B(T), C(T), D(T);

        // 读入数据
        for (int i = 0; i < T; i++) {
            cin >> A[i] >> B[i] >> C[i] >> D[i];
        }

        // 1. 统计 A+B 的频次（每轮循环会自动重置这个 map）
        unordered_map<int, int> count_AB;
        for (int i = 0; i < T; i++) {
            for (int j = 0; j < T; j++) {
                count_AB[A[i] + B[j]]++;
            }
        }

        // 2. 匹配 C+D
        long long ans = 0; // 用 long long 保证安全
        for (int i = 0; i < T; i++) {
            for (int j = 0; j < T; j++) {
                int target = -(C[i] + D[j]);
                // 直接使用 count 查询，如果不存在则返回 0
                if (count_AB.find(target) != count_AB.end()) {
                    ans += count_AB[target];
                }
            }
        }

        // 输出结果并换行
        cout << ans << endl;
        
        // 如果题目要求每组数据后有空行（例如 UVa），可以在这里加 if(N) cout << endl;
    }

    return 0;
}