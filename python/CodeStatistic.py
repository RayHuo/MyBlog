import os
import os.path
import sys

direct = "./fileTest/" # only can use relative path, not absolute path

print "Files under direct : ", direct

cpptotal = 0
pytotal = 0
total = 0
for parent, dirnames, filenames in os.walk(direct) :
    for filename in filenames :
        # os.path.splitext() will split the filename into two part : filename and extendname, "abc.txt" : "abc" and ".txt"
        if os.path.splitext(filename)[1] == '.cpp' :    # only output the file end with '.cpp'
        #if os.path.splitext(filename)[0] == 'print' :  
            f = open(direct + filename)
            count = 0
            line = f.readline()
            while line : 
                tmp = line.lstrip(' \t')  # delete the starting ' ' and '\t' in line, here must use tmp to hold the return
                # print tmp
                if tmp[0:2] != "//" :
                    count += 1
                line = f.readline()
                
            #print "%s Total line num = %d ." % (filename, count)
            f.close()
            cpptotal += count

        if os.path.splitext(filename)[1] == '.py' :
            f = open(direct + filename)
            count = 0
            line = f.readline()
            while line :
                tmp = line.lstrip(' \t')
                if tmp[0] != '#' :
                    count += 1
                line = f.readline()
            f.close()
            pytotal += count

print "Python code total lines : %d." % pytotal
print "C++ code total lines : %d." % cpptotal
print "Total code lines : %d." % (pytotal + cpptotal)