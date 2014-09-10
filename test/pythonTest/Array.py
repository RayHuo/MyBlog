arrays = []
arrays.append(1)
arrays.append(2)
arrays.remove(1)
arrays.append(3)
arrays.append(1)

print len(arrays)
print arrays.index(2)

arrays.sort()
print arrays
print ""