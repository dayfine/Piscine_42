import sys
from random import randint

prog, x, y, density = sys.argv

x = int(x)
y = int(y)
density = int(density)

print("{}.ox".format(y))

for i in range(y):
    for j in range(x):
        if randint(0, x * y) < density:
            sys.stdout.write('o')
        else:
            sys.stdout.write('.')
    sys.stdout.write('\n')

