/*
STL 中的 queue 的基本操作有
    queue<Type>q        : 定义队列
    q.push(item)        : 把 item 放入队列
    q.front()           : 返回队首元素 , 但不删除
    q.pop()             : 删除队首元素
    q.back()            : 返回队尾元素
    q.size()            : 返回元素个数
    q.empty             : 检查队列是否为空
*/


// 第一行输入一个数字 N 
// 接下来的 N 行中 , 每行输入一个数字为操作命令:    1 表示入队      2 表示出队并输出    3 表示队列中元素的个数并输出
#include<bits\stdc++.h>

using namespace std;

int main()
{
    queue<int>qu;
    int n;
    cin >> n;
    while(n--)
    {
        int choice;
        cin >> choice;
        switch(choice){
            case 1:
                int element; cin >> element;
                qu.push(element);
                break;
            case 2:
                if (qu.empty())
                {
                    cout << "no" << endl;
                    break;
                }
                int num;
                num = qu.front();
                qu.pop();
                cout << num << endl;
                break;
            case 3:
                cout << qu.size() << endl;
                break;
        }
    }
    return 0;
}