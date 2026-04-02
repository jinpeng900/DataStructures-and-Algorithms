# include<bits/stdc++.h>
using namespace std;

/*

lower_bound
    功能:查找低一个大于或等于目标值的元素位置
    返回 : 指向该元素的迭代器 , 如果找不到 , 返回末尾迭代器

upper_bound
    功能:查找低一个大于目标值的元素位置
    返回 : 指向该元素的迭代器 , 如果找不到 , 返回末尾迭代器

*/


int main() {
    // 准备一个已排序的 vector，注意其中有重复元素 3
    std::vector<int> data = {1, 2, 3, 3, 3, 4, 5, 8};
    int target = 3;

    // 1. 使用 lower_bound 查找第一个 >= 3 的位置
    auto low = std::lower_bound(data.begin(), data.end(), target);
    
    // 2. 使用 upper_bound 查找第一个 > 3 的位置
    auto up = std::upper_bound(data.begin(), data.end(), target);

    // 计算索引（下标）
    int low_idx = std::distance(data.begin(), low);
    int up_idx = std::distance(data.begin(), up);

    // 输出结果
    std::cout << "数据源: {1, 2, 3, 3, 3, 4, 5, 8}" << std::endl;
    std::cout << "目标值: " << target << "\n" << std::endl;

    std::cout << "lower_bound (第一个 >= 3):" << std::endl;
    std::cout << " - 下标: " << low_idx << std::endl;
    std::cout << " - 指向的值: " << *low << std::endl;

    std::cout << "\nupper_bound (第一个 > 3):" << std::endl;
    std::cout << " - 下标: " << up_idx << std::endl;
    std::cout << " - 指向的值: " << *up << std::endl;

    // 实用技巧：计算目标值出现的次数
    std::cout << "\n目标值 " << target << " 出现的次数: " << (up - low) << std::endl;

    return 0;
}