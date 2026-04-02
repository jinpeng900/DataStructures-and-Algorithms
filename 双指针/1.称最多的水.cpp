#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n = static_cast<int>(height.size());
    int left1 = 0;
    int right1 = n - 1;
    int res = 0; // 修改变量名，避免与内部 ans 冲突

    while (left1 < right1) { // 1. 左右指针重合时面积必为0，用 < 即可
        // 2. 逻辑错误：木桶效应取决于“短板”，应该用 min 而不是 max
        int h = min(height[left1], height[right1]); 
        
        // 3. 面积计算：宽度是 right - left
        res = max(res, h * (right1 - left1));
        
        // 4. 移动逻辑：哪边短移动哪边
        if (height[left1] < height[right1]) {
            left1++;
        }
        else {
            right1--; // 5. 错误修正：右指针应该是向左移动 (right--)
        }
    }

    return res;
}

int main() {
    vector<int> q1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "最大蓄水量: " << maxArea(q1) << endl; 
    return 0;
}