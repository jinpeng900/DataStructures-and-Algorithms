#include<bits/stdc++.h>
using namespace std;

const int N = 30;
int sum = 0;
stack<int> st[4];

void move(int x , int y , int n){       // 移动圆盘
    int element = st[x].top();          // 从杆子 x 上取出顶部的圆盘放到杆子 y 上
    st[x].pop();
    st[y].push(element);
    sum++;
    char a , b;     // 用于输出
    if (x == 1) a = 'A';    
    if (x == 2) a = 'B';
    if (x == 3) a = 'C';
    if (y == 1) b = 'A';
    if (y == 2) b = 'B';
    if (y == 3) b = 'C';
    cout << a << " -> " << b << endl;
    sum++;
}

void  hanoi(int n , int x , int y , int z){
    if (n == 1){
        move(x , z , n);
        return;
    }
    hanoi(n-1 , x , z , y);
    move(x , z , n);
    hanoi(n-1 , y , x , z);
}

int main()
{
    int n;
    cin >> n;
    for (int i = n ; i >= 1 ; i--){
        st[1].push(i);
    }
    hanoi(n, 1, 2, 3);
    cout << sum << endl;
    return 0;
}

