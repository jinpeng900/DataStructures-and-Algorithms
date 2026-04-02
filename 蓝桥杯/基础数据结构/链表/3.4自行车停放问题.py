# 自行车停放
n = int(input())

a = int(input())

bicycles = []

bicycles.append(a)

for i in range(n-1):
    x , y , z = map(int , input().split())
    if z == 0:
        bicycles.insert(bicycles.index(y) , x)
    else:
        bicycles.insert(bicycles.index(y) + 1 , x)

for i in bicycles:
    print(i , end = " ")