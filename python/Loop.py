num = input("Loop size : ")

for i in range(1, num) : 
	print i

print ""

for i in range(num) : 
	print i

print ""

for i in range(1, num, 2) : 	# the last parameter means i += 2 every time in the loop
	print i

print ""

i = 0
while i < num : # 
	print i
	i += 1		# no i++

while True :
	choose = raw_input("Go on or quit : ")
	if choose == "quit" :
		break
	else :
		continue
print "Break out" 