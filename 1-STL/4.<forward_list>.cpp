#include <forward_list>
#include <iostream>

using namespace std;

/*
forward_list 教程

一、核心特性
1) 单向链表
	- 只能从前往后遍历，不支持反向遍历。
	- 已知位置时，插入/删除可做到 O(1)。

2) 低内存开销
	- 每个节点通常只保存“下一个节点”指针。
	- 相比 list（双向链表）更省内存。

3) 不支持随机访问
	- 没有 []、at()。
	- 只能通过迭代器访问元素。

4) 性能与适用场景
	- 头部操作快：push_front/pop_front。
	- 中间插删快：insert_after/erase_after（已知前驱位置）。
	- 不适合按下标频繁访问。

二、基本语法
	#include <forward_list>
	std::forward_list<T> fl;

三、常见构造方式
	- 默认构造：forward_list<int> a;
	- 列表初始化：forward_list<int> b = {1, 2, 3};
	- 范围构造：forward_list<int> c(b.begin(), b.end());

四、常用成员函数
	push_front(const T& value)     头插
	pop_front()                    删除头结点
	before_begin()                 头结点前一个“虚拟位置”
	begin() / end()                正向迭代器
	insert_after(pos, value)       在 pos 后插入
	erase_after(pos)               删除 pos 后一个元素
	remove(value)                  删除所有等于 value 的元素
	sort()                         排序
	merge(other)                   合并两个已排序链表
	reverse()                      反转
	clear()                        清空
	empty()                        判空
	front()                        访问首元素

说明：forward_list 没有 back()，也通常不提供 O(1) 的 size()。
*/

static void print_list(const forward_list<int>& fl, const string& title) {
	 cout << title;
	 for (int x : fl) {
		  cout << x << ' ';
	 }
	 cout << '\n';
}

int main() {
	 // 实例1：基本操作
	 forward_list<int> fl = {20, 30, 40};
	 print_list(fl, "初始: ");

	 // 1) push_front / pop_front
	 fl.push_front(10);
	 print_list(fl, "push_front(10) 后: ");
	 fl.pop_front();
	 print_list(fl, "pop_front() 后: ");

	 // 2) before_begin + insert_after（在头部前驱后插入，相当于头插）
	 auto bb = fl.before_begin();
	 fl.insert_after(bb, 5);
	 print_list(fl, "insert_after(before_begin, 5) 后: ");

	 // 3) 在指定位置后插入
	 auto it = fl.begin();      // 指向第一个元素
	 fl.insert_after(it, 25);   // 在第一个元素后插入 25
	 print_list(fl, "insert_after(begin, 25) 后: ");

	 // 4) erase_after：删除某位置后一个元素
	 fl.erase_after(fl.begin());
	 print_list(fl, "erase_after(begin) 后: ");

	 // 5) remove：删除所有等于某值的元素
	 fl.push_front(30);
	 fl.push_front(30);
	 print_list(fl, "加入重复 30 后: ");
	 fl.remove(30);
	 print_list(fl, "remove(30) 后: ");

	 // 6) sort / reverse
	 fl.push_front(100);
	 fl.push_front(1);
	 fl.sort();
	 print_list(fl, "sort() 后: ");
	 fl.reverse();
	 print_list(fl, "reverse() 后: ");

	 // 7) merge：两个链表先排序
	 forward_list<int> other = {2, 6, 8};
	 fl.sort();
	 other.sort();
	 fl.merge(other);
	 print_list(fl, "merge(other) 后 fl: ");
	 cout << "other 是否为空: " << boolalpha << other.empty() << '\n';

	 // 8) front / empty / clear
	 if (!fl.empty()) {
		  cout << "front = " << fl.front() << '\n';
	 }
	 fl.clear();
	 cout << "clear() 后是否为空: " << boolalpha << fl.empty() << '\n';

	 return 0;
}
