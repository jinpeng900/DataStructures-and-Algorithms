/*
        小明买了 n 件白色的衣服 , 他希望对这些衣服进行染色 , 每次染色时 , 他会将某种颜色的所有衣服寄给染色厂 , 第 i 件衣服的邮费为 ai 元 
    染色厂会按照小明的要求将其中一部分衣服染成同一种任意的颜色 , 之后将衣服寄给小明 , 请问小明要将 n 件衣服染成不同颜色的最小代价是什么? 

    此题可反向思考 , 所有衣服当作开始各个不同颜色 , 每次染色时 , 将寄来的衣服染成相同颜色 , 直至所有衣服颜色相同 , 代价就是这些衣服的邮费之和
    类似于哈夫曼树 , 每次将两个最小的数合并 , 直到合并成一个数
    本题可用优先队列维护当前所有颜色的邮费之和 , 每次取出最小的两个数合并 , 直到合并成一个数
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n; cin >> n;
    priority_queue<ll,vector<ll>,greater<ll>> q;        // 队首是最小的元素
    for(ll i = 0 ; i < n ; ++i){
        ll a ; cin >> a;
        q.push(a);
    }
    ll sum = 0;
    while (q.size() > 1)    
    {
        ll a = q.top(); q.pop();            // 取出最小的两个数
        ll b = q.top(); q.pop();
        ll z = a+b;
        sum += z;
        q.push(z);          //  入队
    }
    cout << sum << endl;
    return 0;
}
