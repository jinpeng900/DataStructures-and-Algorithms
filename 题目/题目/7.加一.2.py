from typing import List

def plusOne(digits: List[int]) -> List[int]:
    for i in range(len(digits)-1 , -1 , -1):
        digits[i] = digits[i] + 1
        if digits[i] != 10:
            return digits
        else:
            digits[i] = 0
    digits = [0] * (len(digits) + 1)
    digits[0] = 1
    return digits

d = [9 , 9 , 8]
ls = plusOne(d)
print(ls)

for i in range(10 , -1 , -1):
    print(i)