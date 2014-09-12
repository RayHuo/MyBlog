a = input("First : ")
b = input("Second : ")

# if-elif-else
# remeber the ":" at the end of the condition
if a == b :
    print "first is equal to second!"
elif a < b :
    print "first is less than second!"
else :
    print "first is larger than second!"

# python has no switch


if a + b < 10 and a * b < 20 : 
    print "%d + %d < 10, and %d * %d < 20" % (a, b, a, b)
elif a + b < 10 or a * b < 20 :
    if not (a + b < 10) : 
        print "%d * %d < 20" % (a, b)
    else : 
        print "%d + %d < 10" % (a, b)
else :
    print "Nothing"