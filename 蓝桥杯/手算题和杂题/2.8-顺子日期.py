"""
小明特别喜欢顺子。
顺子指的就是连续的3个数字：123、456等。
顺子日期指的就是在日期的 yyyymmdd 表示法中，存在任意连续的三位数是一个顺子的日期。
例如20220123 就是一个顺子日期，因为它包含一个顺子123；而20221023 则不是一个顺子日期，它一个顺子也没有。小明想知道在2022年一共有多少个顺子日期。
"""
from datetime import *
dt1 = datetime(2022 , 1 , 1)
cnt = 0
for i in range(0 , 365):
    s = "%02d%02d%02d" % (dt1.year , dt1.month , dt1.day)
    dt1 += timedelta(days=1)
    if "012" in s or "123" in s or "234" in s or "345" in s or "456" in s or "567" in s or "678" in s or "789" in s:
        cnt += 1
print(cnt)