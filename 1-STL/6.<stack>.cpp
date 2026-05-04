#include <deque>
#include <iostream>
#include <stack>

using namespace std;

/*
stack 教程

一、特性总览
1) 大小分配
	- stack 是容器适配器，默认基于 deque。
	- 元素数量可动态变化，只能在栈顶操作。

2) 边界检查
	- 无 at()、无下标访问。
	- 使用 top() 前应先判断 empty()。

3) 内存管理
	- 内存管理由底层容器负责（默认 deque）。
	- 可换底层容器，如 vector、list（需满足接口要求）。

4) 性能特点
	- push / pop / top 平均 O(1)。
	- 适合后进先出（LIFO）场景。

二、常用成员函数
stack<T> s;                 创建空栈
empty()                     判空
size()                      元素个数
top()                       访问栈顶元素
push(value)                 入栈
emplace(args...)            原地构造入栈
pop()                       出栈（不返回值）
swap(other)                 交换两个栈
*/

int main() {
	 cout << "实例1：基本操作" << '\n';

	 stack<int> st;
	 cout << "初始 empty = " << boolalpha << st.empty() << '\n';

	 // 1) push / emplace 入栈
	 st.push(10);
	 st.push(20);
	 st.emplace(30);

	 // 2) top / size
	 cout << "top = " << st.top() << ", size = " << st.size() << '\n';

	 // 3) pop 出栈（先读 top 再 pop）
	 while (!st.empty()) {
		  cout << "pop " << st.top() << '\n';
		  st.pop();
	 }
	 cout << "出栈后 empty = " << boolalpha << st.empty() << '\n';

	 cout << "\n实例2：swap" << '\n';
	 stack<int> a;
	 a.push(1);
	 a.push(2);

	 stack<int> b;
	 b.push(100);

	 a.swap(b);
	 cout << "swap 后 a.top = " << a.top() << ", b.top = " << b.top() << '\n';

	 cout << "\n实例3：指定底层容器（deque）" << '\n';
	 stack<int, deque<int>> st2;
	 st2.push(7);
	 st2.push(8);
	 cout << "st2.top = " << st2.top() << '\n';

	 return 0;
}
