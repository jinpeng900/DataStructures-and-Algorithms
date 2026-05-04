#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>

using namespace std;

/*
list 特性总览
1) 大小分配
   - 双向链表，长度可变。
   - 每个元素独立节点分配，不要求连续内存。

2) 边界检查
   - 不支持下标访问（没有 []、at()）。
   - 通过迭代器访问，越界主要由迭代器使用错误导致。

3) 内存管理
   - 节点分散存储，插入删除通常只改指针。
   - 中间插入/删除不会整体搬迁元素。
   - 与 vector 相比，额外指针开销更大，缓存局部性更差。

4) 性能特点
   - 已知位置插入/删除是 O(1)。
   - 随机访问慢，访问第 k 个元素是 O(n)。
   - 适合频繁中间插删，不适合高频下标访问。

常用成员函数速览
push_back(const T& val)      在链表末尾添加元素
push_front(const T& val)     在链表头部添加元素
pop_back()                   删除链表末尾的元素
pop_front()                  删除链表头部的元素
insert(iterator pos, val)    在指定位置插入元素
erase(iterator pos)          删除指定位置的元素
clear()                      清空所有元素
size()                       返回链表中的元素数量
empty()                      检查链表是否为空
front()                      返回链表第一个元素
back()                       返回链表最后一个元素
remove(const T& val)         删除所有等于指定值的元素
sort()                       对链表中的元素进行排序
merge(list& other)           合并另一个已排序的链表
reverse()                    反转链表
begin() / end()              返回链表的起始/结束迭代器
*/

int main() {
	cout << "实例1：基本操作" << '\n';

	// 1) 定义与初始化
	list<int> lst = {10, 20, 30};

	// 2) push_front / push_back
	lst.push_front(5);
	lst.push_back(40);

	// 3) front / back
	cout << "front = " << lst.front() << ", back = " << lst.back() << '\n';

	// 4) begin / end 遍历
	cout << "当前链表: ";
	for (auto it = lst.begin(); it != lst.end(); ++it) {
		cout << *it << ' ';
	}
	cout << '\n';

	// 5) insert(iterator pos, val)
	auto pos = lst.begin();
	advance(pos, 2);
	lst.insert(pos, 99);

	// 6) erase(iterator pos)
	auto del = lst.begin();
	advance(del, 1);
	lst.erase(del);

	// 7) remove(val)
	lst.push_back(99);
	lst.remove(99);

	// 8) pop_front / pop_back
	lst.pop_front();
	lst.pop_back();

	cout << "操作后链表: ";
	for (int x : lst) {
		cout << x << ' ';
	}
	cout << "\nsize = " << lst.size() << ", empty = " << boolalpha << lst.empty() << '\n';

	// 9) sort / reverse
	lst.push_back(7);
	lst.push_back(3);
	lst.sort();
	cout << "sort 后: ";
	for (int x : lst) {
		cout << x << ' ';
	}
	cout << '\n';

	lst.reverse();
	cout << "reverse 后: ";
	for (int x : lst) {
		cout << x << ' ';
	}
	cout << '\n';

	// 10) merge(list& other)：两个链表都需先排序
	list<int> other = {2, 6, 8};
	lst.sort();
	other.sort();
	lst.merge(other);
	cout << "merge 后 lst: ";
	for (int x : lst) {
		cout << x << ' ';
	}
	cout << "\nmerge 后 other size = " << other.size() << '\n';

	// 11) clear
	lst.clear();
	cout << "clear 后 size = " << lst.size() << ", empty = " << boolalpha << lst.empty() << '\n';

	return 0;
}
