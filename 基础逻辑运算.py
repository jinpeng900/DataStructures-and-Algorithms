# 逻辑与
def and_op(a , b):
    return a and b

# 逻辑或
def or_op(a , b):
    return a or b

# 逻辑非
def not_op(a):
    return not a

# a -> b
def implies_op(a , b):
    return not a or b

# a <-> b 
def equivalent_op(a , b):
    return implies_op(a , b) and implies_op(b , a)

ls = [[0 , 0],
      [0 , 1],
      [1 , 0],
      [1 , 1]]

# 测试一波

for i in range(0 , 4):
    a = ls[i][0]
    b = ls[i][1]
    ans = or_op(b , not_op(and_op(or_op(not_op(a) , b) , a)))
    if ans == 0:
        print("NO")
        break
else:
    print("Yes")
