#include <deque>
#include <iostream>
#include <queue>

using namespace std;

/*
queue 教程

一、特性总览
1) 大小分配
	- queue 是容器适配器，默认基于 deque。
	- 元素数量动态变化，遵循先进先出（FIFO）。

2) 边界检查
	- 无下标访问、无 at()。
	- 访问 front()/back() 前先判断 empty()。

3) 内存管理
	- 由底层容器负责内存管理（默认 deque）。
	- 也可用 list 作为底层容器（需满足接口）。

4) 性能特点
	- push 在尾部、pop 在头部，平均 O(1)。
	- 适合排队处理、BFS 等场景。

二、常用成员函数
queue<T> q;                 创建空队列
empty()                     判空
size()                      元素个数
front()                     访问队头
back()                      访问队尾
push(value)                 尾部入队
emplace(args...)            原地构造入队
pop()                       头部出队（不返回值）
swap(other)                 交换两个队列
*/

int main() {
	 cout << "实例1：基本操作" << '\n';

	 queue<int> q;
	 cout << "初始 empty = " << boolalpha << q.empty() << '\n';

	 // 1) 入队
	 q.push(10);
	 q.push(20);
	 q.emplace(30);

	 // 2) 查看队头与队尾
	 cout << "front = " << q.front() << ", back = " << q.back() << '\n';
	 cout << "size = " << q.size() << '\n';

	 // 3) 出队：先读 front 再 pop
	 while (!q.empty()) {
		  cout << "pop " << q.front() << '\n';
		  q.pop();
	 }
	 cout << "出队后 empty = " << boolalpha << q.empty() << '\n';

	 cout << "\n实例2：swap" << '\n';
	 queue<int> a;
	 a.push(1);
	 a.push(2);

	 queue<int> b;
	 b.push(100);
	 b.push(200);

	 a.swap(b);
	 cout << "swap 后 a.front = " << a.front() << ", a.back = " << a.back() << '\n';
	 cout << "swap 后 b.front = " << b.front() << ", b.back = " << b.back() << '\n';

	 cout << "\n实例3：指定底层容器（deque）" << '\n';
	 queue<int, deque<int>> q2;
	 q2.push(7);
	 q2.push(8);
	 cout << "q2.front = " << q2.front() << ", q2.back = " << q2.back() << '\n';

	 return 0;
}
