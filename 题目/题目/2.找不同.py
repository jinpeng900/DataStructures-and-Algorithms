# 字典查找
def findDifference(s:str , t:str) -> str:
    d = {}
    for i in t:
        d[i] = d.get(i , 0) + 1
    for i in s:
        d[i] = d.get(i , 0) - 1
    for i in d:
        if d[i] == 1:
            return i


s = "abcd"
t = "abcde"
print(findDifference(s , t))