a = input("a : ")	# the input will be int and float, string kind, input is completed by "eval(raw_input())"
b = input("b : ")
print "a + b = ", a + b 
print "a = %d, b = %d, a + b = %d." % (a, b, a+b)

c = raw_input("Your name : ")	# the input will be string kind
print "Hello, ", c
print "Goodbye, " + c
print "The length of your name %s is %d." % (c, len(c))		# len() is a in-build function of python

pi = 3.1414926
print "d = %.4f." % pi

