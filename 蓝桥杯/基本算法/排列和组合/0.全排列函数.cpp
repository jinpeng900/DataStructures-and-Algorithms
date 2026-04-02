/*

C++全排列函数 next_permutation()
    函数 next_permutation() 的定义有以下两种形式
        bool next_permutation(iterator start, iterator end);
        bool next_permutation(iterator start, iterator end, compare comp);

        返回值: 如果有下一个排列, 则返回 true, 否则返回 false.
            每执行一次 next_permutation(), 新的排列就会被放到原来的空间中
            其排列范围是 [start, end)

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "bca";
    do{
        cout << s1 << endl;
    }while(next_permutation(s1.begin() , s1.end()));            // 逐个输出更大的全排列

    cout << "\n" << endl;

    string s2 = "bca";
    sort(s2.begin() , s2.end());
    do{
        cout << s2 << endl;
    }while(next_permutation(s2.begin() , s2.end()));            // 逐个输出更大的全排列
    return 0;
}