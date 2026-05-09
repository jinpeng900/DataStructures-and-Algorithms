#include <bits/stdc++.h>
using namespace std;

// deque 教程：
// - 双端队列（double-ended queue），支持在两端高效插入/删除
// - 支持随机访问（operator[] / at），但内部实现不是单一连续内存
// - 常用于需要在两端都操作的场景（如滑动窗口、双端缓存等）
// - 复杂度：push/pop front/back 为 O(1) 摊销，随机访问为 O(1)

// 示例：展示常用接口与用法

void demo_basic()
{
    cout << "=== deque 基本操作 ===\n";
    deque<int> dq; // 空 deque

    // 在尾部与头部插入
    dq.push_back(3); // [3]
    dq.push_front(1); // [1,3]
    dq.push_back(4); // [1,3,4]
    dq.push_front(0); // [0,1,3,4]

    // 访问首尾与随机访问
    cout << "front=" << dq.front() << " back=" << dq.back() << "\n";
    cout << "dq[1]=" << dq[1] << " dq.at(2)=" << dq.at(2) << "\n";

    // 遍历
    cout << "内容：";
    for (auto &v : dq) cout << v << ' ';
    cout << "\n";

    // 删除
    dq.pop_front(); // 删除头
    dq.pop_back();  // 删除尾
    cout << "删除后：";
    for (auto v : dq) cout << v << ' ';
    cout << "\n";

    // 插入/删除中间（使用迭代器）
    auto it = dq.begin();
    ++it; // 指向原位置
    dq.insert(it, 99); // 在 it 之前插入
    cout << "insert 后：";
    for (auto v : dq) cout << v << ' ';
    cout << "\n";

    dq.erase(dq.begin()+1); // 删除第二个元素
    cout << "erase 后：";
    for (auto v : dq) cout << v << ' ';
    cout << "\n";

    // emplace 系列
    dq.emplace_back(77);
    dq.emplace_front(-1);
    cout << "emplace 后：";
    for (auto v : dq) cout << v << ' ';
    cout << "\n";

    // 其他工具函数
    cout << "size=" << dq.size() << " empty=" << dq.empty() << "\n";
    dq.clear();
    cout << "clear 后 size=" << dq.size() << "\n";
}

// 示例：用 deque 模拟队列与栈
void demo_stack_queue()
{
    cout << "=== deque 作为队列/栈 ===\n";
    deque<int> dq;
    // 作为队列（FIFO）
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    cout << "队头=" << dq.front() << " 队尾=" << dq.back() << "\n";
    dq.pop_front(); // 出队
    cout << "出队后队头=" << dq.front() << "\n";

    // 作为栈（LIFO）
    dq.clear();
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    cout << "栈顶=" << dq.back() << "\n";
    dq.pop_back(); // 出栈
    cout << "出栈后栈顶=" << dq.back() << "\n";
}

// 示例：滑动窗口最大值（单调队列，展示 deque 的典型应用）
vector<int> maxSlidingWindow(vector<int>& nums, int k){
    vector<int> ans;
    if (k==0) return ans;
    deque<int> dq; // 存下标，保持单调递减
    for (int i = 0; i < (int)nums.size(); ++i) {
        // 清除窗口外的下标
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        // 保持单调递减
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main()
{
    demo_basic();
    cout << "\n";
    demo_stack_queue();
    cout << "\n";

    cout << "=== 滑动窗口最大值示例 ===\n";
    vector<int> a = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    auto r = maxSlidingWindow(a,k);
    cout << "输入：";
    for (int x : a) cout << x << ' ';
    cout << "\n窗口大小=" << k << " 输出：";
    for (int x : r) cout << x << ' ';
    cout << "\n";

    return 0;
}
