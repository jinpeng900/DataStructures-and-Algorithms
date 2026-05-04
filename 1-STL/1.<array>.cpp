// std::array 特性速览
// 1) 大小分配：编译期固定长度，不能扩容或缩容。
// 2) 边界检查：operator[] 不检查边界；at() 越界会抛出异常。
// 3) 内存管理：对象通常在栈上，元素连续存储，无额外堆分配。
// 4) 性能特点：访问开销接近原生数组，拷贝是整体拷贝，缓存友好。
// 5) 使用场景：长度已知且固定的数据；若要动态增删请用 vector。

#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
	// 1) 定义：array<类型, 固定长度>
	array<int, 5> a = {10, 20, 30, 40, 50};

	// 2) 访问元素：[] 不检查边界，at() 会检查边界
	cout << "a[0] = " << a[0] << '\n';
	cout << "a.at(1) = " << a.at(1) << '\n';

	// 3) 头尾元素
	cout << "front = " << a.front() << ", back = " << a.back() << '\n';

	// 4) 大小相关
	cout << "size = " << a.size() << '\n';
	cout << "empty = " << boolalpha << a.empty() << '\n';

	// 5) 遍历方式一：下标遍历
	cout << "index loop: ";
	for (size_t i = 0; i < a.size(); ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	// 6) 遍历方式二：范围 for（最常用）
	cout << "range loop: ";
	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';

	// 7) 修改：fill 把所有元素改成同一个值
	a.fill(7);
	cout << "after fill(7): ";
	for (int x : a) {
		cout << x << ' ';
	}
	cout << '\n';

	// 8) 排序与算法：array 可以直接配合 STL 算法
	array<int, 5> b = {5, 1, 4, 2, 3};
	sort(b.begin(), b.end());
	cout << "sorted b: ";
	for (int x : b) {
		cout << x << ' ';
	}
	cout << '\n';

	// 9) 累加：accumulate 求和
	int sum = accumulate(b.begin(), b.end(), 0);
	cout << "sum(b) = " << sum << '\n';

	// 10) 交换两个 array（长度和类型必须一致）
	array<int, 5> c = {100, 200, 300, 400, 500};
	b.swap(c);
	cout << "after swap, b: ";
	for (int x : b) {
		cout << x << ' ';
	}
	cout << '\n';

	// 11) data()：拿到底层连续内存首地址（与 C 风格接口配合）
	int* p = b.data();
	cout << "*data = " << *p << '\n';

	// 12) 小结：
	// array 长度固定、开销小、支持 STL 算法；
	// 若需要动态扩容，请使用 vector。

	return 0;
}
