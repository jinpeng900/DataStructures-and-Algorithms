#include <deque>
#include <iostream>
#include <string>

using namespace std;

/*
deque 教程

一、特性总览
1) 大小分配
   - 动态大小，支持头尾两端高效插入删除。
   - 不是单块连续内存，通常是分段连续结构。

2) 边界检查
   - at(pos) 有范围检查，越界会抛异常。
   - operator[] 无范围检查，速度更快。

3) 内存管理
   - 比 vector 更擅长头部操作。
   - 比 list 更节省指针开销，但内存连续性不如 vector。

4) 性能特点
   - push_front / push_back 平均 O(1)。
   - 随机访问 O(1)。
   - 中间 insert / erase 可能 O(n)。

二、函数速查
deque()                                    默认构造函数，创建空 deque。
deque(size_type n)                         创建 n 个默认值元素。
deque(size_type n, const T& value)         创建 n 个值为 value 的元素。
deque(initializer_list<T> il)              用初始化列表构造。
operator=                                  赋值操作。
assign()                                   替换所有元素。
at(size_type pos)                          带范围检查访问。
operator[](size_type pos)                  不带范围检查访问。
front()                                    访问首元素。
back()                                     访问尾元素。
begin() / end()                            正向迭代器。
rbegin() / rend()                          逆向迭代器。
empty()                                    判空。
size()                                     元素个数。
max_size()                                 理论可容纳最大元素个数。
clear()                                    清空。
insert(iterator pos, const T& value)       指定位置插入。
erase(iterator pos)                        删除指定位置。
push_back(const T& value)                  尾插。
pop_back()                                 尾删。
push_front(const T& value)                 头插。
pop_front()                                头删。
resize(size_type count)                    调整大小。
swap(deque& other)                         交换容器内容。
get_allocator()                            获取分配器对象副本。
*/

static void print_deque(const deque<int>& dq, const string& title) {
	cout << title;
	for (int x : dq) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main() {
	cout << "实例1：构造函数" << '\n';
	deque<int> a;                 // deque()
	deque<int> b(3);              // deque(n)
	deque<int> c(4, 7);           // deque(n, value)
	deque<int> d = {1, 2, 3, 4};  // deque(initializer_list)

	print_deque(b, "b(3): ");
	print_deque(c, "c(4,7): ");
	print_deque(d, "d={1,2,3,4}: ");

	cout << "\n实例2：赋值与替换" << '\n';
	a = d;                    // operator=
	a.assign(5, 9);           // assign(count, value)
	print_deque(a, "a.assign(5,9): ");

	cout << "\n实例3：访问元素" << '\n';
	cout << "a.at(0) = " << a.at(0) << '\n';
	cout << "a[1] = " << a[1] << '\n';
	cout << "front = " << a.front() << ", back = " << a.back() << '\n';

	cout << "\n实例4：头尾操作" << '\n';
	a.push_back(100);
	a.push_front(200);
	print_deque(a, "push_front/push_back 后: ");
	a.pop_back();
	a.pop_front();
	print_deque(a, "pop_front/pop_back 后: ");

	cout << "\n实例5：insert / erase" << '\n';
	auto it = a.begin();
	a.insert(it + 1, 88);
	print_deque(a, "insert(begin+1,88) 后: ");
	a.erase(a.begin() + 2);
	print_deque(a, "erase(begin+2) 后: ");

	cout << "\n实例6：迭代器遍历" << '\n';
	cout << "正向(begin/end): ";
	for (auto p = a.begin(); p != a.end(); ++p) {
		cout << *p << ' ';
	}
	cout << "\n逆向(rbegin/rend): ";
	for (auto p = a.rbegin(); p != a.rend(); ++p) {
		cout << *p << ' ';
	}
	cout << '\n';

	cout << "\n实例7：容量与状态" << '\n';
	cout << "empty = " << boolalpha << a.empty() << '\n';
	cout << "size = " << a.size() << '\n';
	cout << "max_size = " << a.max_size() << '\n';

	cout << "\n实例8：resize / swap / clear" << '\n';
	a.resize(8);
	print_deque(a, "resize(8) 后: ");

	deque<int> other = {11, 22, 33};
	a.swap(other);
	print_deque(a, "swap 后 a: ");
	print_deque(other, "swap 后 other: ");

	other.clear();
	cout << "other.clear() 后 empty = " << boolalpha << other.empty() << '\n';

	cout << "\n实例9：get_allocator" << '\n';
	auto alloc = a.get_allocator();
	int* p = alloc.allocate(2);
	alloc.deallocate(p, 2);
	cout << "get_allocator() 演示完成" << '\n';

	return 0;
}
