'''
蓝桥杯.基础数据结构.栈.3.8砍竹子(暴力求解) 的 Docstring
    题目描述 : 小明面前有 n 根竹子排成一排 , 一开始第 i 根竹子的高度为 h[i] , 小明可以进行如下操作 :
        可以对连续的多根相同高度的竹子进行操作 , 假设这些竹子的高度均为 H , 则操作后这些竹子的高度均为 floor(sqrt(floor(H / 2) + 1)) (向下取整)
        小明想知道最少需要进行多少次操作 , 才能使得所有的竹子的高度均为 1
'''


from math import *
n = int(input())
a = list(map(int , input().split()))

ans = 0
while True:
    idx = 0
    for i in range(n):
        if a[i] > a[idx] : idx = i
    if a[idx] == 1 : break
    val = a[idx]

    for i in range(idx , n):
        if a[i] != val : break
        if val == 2 : a[i] = 1
        else : a[i] = floor(sqrt(floor(val / 2) + 1))
    ans += 1
print(ans)
