num = 0

for i in range(1 , 2022):
    if '2' in str(i) or '0' in str(i) or '1' in str(i) or '9' in str(i):
        num += i**2

print(num)