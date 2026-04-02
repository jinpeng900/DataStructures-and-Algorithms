/*
    STL 中的 sort() 函数

        (1) void sort (RandomAccessIterator first, RandomAccessIterator last);
        (2) void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);

        其中，first 是指向待排序数组的第一个元素的迭代器，last 是指向待排序数组的最后一个元素的下一个位置的迭代器。
        comp 是一个可选参数，用于指定排序的规则。

        返回值：无
        复杂度：O(nlogn)

        排序范围：[first, last) ，即包含 first 指向的元素，不包含 last 指向的元素。

    sort() 自带 4 种排序规则：
        (1) less<T> ，按元素的默认排序规则排序，即 operator<()。
        (2) greater<T> ，按元素的默认排序规则排序，即 operator>()。
        (3) less_equal<T> ，按元素的默认排序规则排序，即 operator<=()。 
        (4) greater_equal<T> ，按元素的默认排序规则排序，即 operator>=()。
*/

#include <bits/stdc++.h>
using namespace std;

bool my_less(int i , int j) {return (i < j);}           //  自定义小于函数
bool my_greater(int i , int j) {return (i > j);}        //  自定义大于函数

int main()
{
    int a[] = {3 , 7 , 2 , 5 , 6 , 8 , 5 , 4};
    sort(a , a+4);          //  对 a 数组的前 4 个元素进行排序
    for(int i = 0 ; i < 8 ; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

