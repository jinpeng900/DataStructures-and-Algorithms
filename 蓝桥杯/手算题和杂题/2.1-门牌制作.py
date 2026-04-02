num = 0
str1 = ''
for i in range(1 , 2021):
    str1 += str(i)
for i in str1:
    if i == '2':
        num += 1
print(num)
