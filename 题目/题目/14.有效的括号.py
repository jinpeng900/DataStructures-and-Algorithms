class Solution:
    def isValid(self , s:str) -> bool:
        ls = list()
        d = {'(':')' , '[':']' , '{':'}'}
        for i in s:
            if i in d.keys():
                ls.append(i)
            else:
                if not ls:
                    return False
                if i == d[ls[-1]]:
                    ls.pop()
                else:
                    return False
        return not ls
    
s = Solution()
print(s.isValid("()[]{}"))
