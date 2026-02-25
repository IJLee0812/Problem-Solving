import sys
x = sys.stdin.readline()
y = sys.stdin.readline()
[print(int(x)*int(y[2-i])) for i in range(3)]
print(int(x)*int(y))