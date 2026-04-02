/*
    C++ 中 STL 优先队列 priority_queue 用堆来实现 , 堆是用二叉树实现的一种数据类型
        定义 priority_queue<Type , Container , Functional>
        Type 是数据类型
        Container 是容器类型 (用数组实现的容器 , 默认为 vector)
        Functional 是比较的方式
    当需要使用自定义的数据类型时才需要传入这三个参数 , 而使用基本数据类型时 , 只需传入数据类型 , 默认为大顶堆

    STL 优先队列操作
        pq.push()       : 入队
        pq.pop()        : 出队
        pq.size()       : 返回当前队列的元素个数
        pq.top()        : 返回队首元素
        pq.empty()      : 判断是否为空
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    pair<int , string> a(1 , "abc") , b(7 , "xyz") , c(5 , "mn");       //  键值对的一种表达方式 , 无查找功能
    priority_queue<pair<int , string>> x;                       // 队首元素总是最大值
    x.push(a);
    x.push(b);
    x.push(c);
    while (!x.empty())
    {
        cout << x.top().first << " " << x.top().second << " --- ";
        x.pop();
    }
    cout << "\n";
    priority_queue<pair<int , string> , vector<pair<int , string>> , greater<pair<int , string>>> y;        // 队首元素总是最小值
    y.push(a);
    y.push(b);
    y.push(c);
    while(!y.empty())
    {
        cout << y.top().first << " " << y.top().second << " --- ";
        y.pop();
    }
    return 0;
}