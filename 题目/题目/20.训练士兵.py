# 训练士兵

n , S = map(int , input().split())

m = list(list(map(int , input().split())) for _ in range(n))

m.sort(key=lambda x : x[1])
spend = 0
sum_m = sum(i[0] for i in m)
team = 0
while sum_m > S:
    team = m[0][1]
    spend = S * team
    sum_m -= m[0][0]
    m.pop(0)
for i in m:
    spend += i[0] * (i[1] - team)

print(spend)







