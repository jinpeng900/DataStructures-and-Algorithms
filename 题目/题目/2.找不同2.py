
def findDifference(s:str , t:str) -> str:
    rev = 0
    for i in s+t:
        rev = rev ^ ord(i)
    return chr(rev)


s = "abcd"
t = "abcd"
print(findDifference(s , t))