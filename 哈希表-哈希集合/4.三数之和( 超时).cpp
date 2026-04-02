#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();

    bool allZero = true;
    for (int x : nums) {
        if (x != 0) {
            allZero = false;
            break;
        }
    }
    if (allZero && n >= 3) return {{0, 0, 0}};

    // 必须排序，否则无法简单去重
    sort(nums.begin(), nums.end());

    // 结构不变：path 存储所有两数之和及其对应的下标对
    // 注意：同一个和可能由多组下标组成，所以用 vector 存 pair
    unordered_map<int, vector<pair<int, int>>> path;
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < j; i++) {
            int a = nums[i] + nums[j];
            path[a].push_back({i, j});
        }
    }

    // 用 set 存储结果，自动处理重复解（如 [0,0,0] 出现多次的情况）
    set<vector<int>> resultSet;

    for (int k = 0; k < n; k++) {
        int b = -nums[k];
        if (path.find(b) != path.end()) {
            // 取出所有能组成和为 b 的下标对
            for (auto& temp : path[b]) {
                // 结构不变：确保下标不重复
                if (temp.first != k && temp.second != k) {
                    vector<int> em = {nums[temp.first], nums[temp.second], nums[k]};
                    // 排序以便 set 去重
                    sort(em.begin(), em.end());
                    resultSet.insert(em);
                }
            }
        }
    }

    // 将 set 转回 vector 结构返回
    return vector<vector<int>>(resultSet.begin(), resultSet.end());
}