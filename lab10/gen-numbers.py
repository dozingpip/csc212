import sys
import random

print sys.argv[1]
for i in range(int(sys.argv[1])):
    print int(random.random() * int(sys.argv[2])),