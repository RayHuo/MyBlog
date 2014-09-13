import os
import os.path

direct = "./fileTest/" # only can use relative path, not absolute path

print "Files under direct : ", direct

for parent, dirnames, filenames in os.walk(direct) :
    for filename in filenames :
            print filename  
