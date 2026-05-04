#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/*
vector 特性总览
1) 大小分配
	- 动态数组，长度可变。
	- size() 是当前元素个数，capacity() 是已分配容量。
	- reserve(n) 预留容量，减少扩容次数。

2) 边界检查
	- v[i] 速度快，不做边界检查。
	- v.at(i) 做边界检查，越界会抛异常。

3) 内存管理
	- 底层是连续内存，可用 data() 取得首地址。
	- 扩容可能触发搬迁，旧指针/迭代器可能失效。
	- clear() 清空元素但通常不释放 capacity。

4) 性能特点
	- 尾部插入/删除 push_back、pop_back 平均 O(1)。
	- 中间或头部插入/删除通常 O(n)。
	- 随机访问 O(1)，适合下标访问场景。
*/

int main() {
	 // 1) 定义与初始化
	 vector<int> v = {10, 20, 30};

	 // 2) 大小与容量
	 cout << "size = " << v.size() << ", capacity = " << v.capacity() << '\n';

	 // 3) 预留容量，避免频繁扩容
	 v.reserve(10);
	 cout << "after reserve(10), capacity = " << v.capacity() << '\n';

	 // 4) 访问元素：[] 与 at()
	 cout << "v[0] = " << v[0] << '\n';
	 cout << "v.at(1) = " << v.at(1) << '\n';
	 cout << "front = " << v.front() << ", back = " << v.back() << '\n';

	 // 5) 常见尾部操作
	 v.push_back(40);
	 v.push_back(50);
	 v.pop_back();

	 // 6) 插入与删除（中间操作）
	 v.insert(v.begin() + 1, 99);   // 在下标 1 位置插入 99
	 v.erase(v.begin() + 2);         // 删除下标 2 元素

	 // 7) 遍历：范围 for
	 cout << "vector: ";
	 for (int x : v) {
		  cout << x << ' ';
	 }
	 cout << '\n';

	 // 8) 排序与求和
	 sort(v.begin(), v.end());
	 int sum = accumulate(v.begin(), v.end(), 0);
	 cout << "sorted: ";
	 for (int x : v) {
		  cout << x << ' ';
	 }
	 cout << "\nsum = " << sum << '\n';

	 // 9) data() 获取连续内存首地址
	 int* p = v.data();
	 cout << "*data = " << *p << '\n';

	 // 10) clear 只清元素，容量通常还在
	 v.clear();
	 cout << "after clear, size = " << v.size() << ", capacity = " << v.capacity() << '\n';

	 // 如需尽量回收容量，可尝试：vector<int>().swap(v);

	 return 0;
}
