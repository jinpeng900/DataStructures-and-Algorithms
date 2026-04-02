def check(n):
    if n[0] == n[3]:
        return False
    if n[1] != n[2]:
        return False
    if n[0] == n[1] or n[2] == n[3]:
        return True
    return False

year = []
for y in range(1 , 10000):
    s = "%04d" % y
    s1 = sorted(s)
    if check(s1):
        year.append(s1)

month = []
for m in range(1 , 13):
    for d in range(1 , 31):
        s = "%02d%02d" % (m , d)
        s1 = sorted(s)
        if check(s1):
            month.append(s1)
        
hour = []
for h in range(0 , 24):
    for t in range(0 , 60):
        s = "%02d%02d" % (h , t)
        s1 = sorted(s)
        if check(s1):
            hour.append(s1)

res = 0
for y in year:
    for d in month:
        for h in hour:
            if y == d and y == h:
                res += 1
print(res)