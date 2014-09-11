def addSum(x) : 
    sum = 0
    for i in range(1, x+1) : 
        sum += i
    return sum

x = input("x is : ")
sum_ = addSum(x)
print "1 + 2 + 3 + ... + %d = %d" % (x, sum_)
