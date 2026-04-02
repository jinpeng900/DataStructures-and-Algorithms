# 整个 20 世纪（1901 年 1 月 1 日 至 2000 年 12 月 31 日），一共有多少个星期一

from datetime import *

dt1 = datetime(1901 , 1 , 1)
dt2 = datetime(2000 , 12 , 31)
 
print(dt1.weekday())
print(dt2.weekday())

dt = dt2 - dt1

print(dt)

print(dt.days)

print(dt.days // 7)