import os
import os.path
import sys

direct = "./fileTest/" # only can use relative path, not absolute path

print "Files under direct : ", direct

for parent, dirnames, filenames in os.walk(direct) :
    for filename in filenames :
        # os.path.splitext() will split the filename into two part : filename and extendname, "abc.txt" : "abc" and ".txt"
        if os.path.splitext(filename)[1] == '.py' :  # only output the file end with '.cpp'
            print filename  
            # f = open(filename)
print ""

for f in os.listdir(direct) : 
    print f[:-2]
    if f[:-2] == '.py' : 
        file_ = open(direct + f)
        print "open successfully!"
        file_.close()