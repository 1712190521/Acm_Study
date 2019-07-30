try:
    while True:
        x,a,y,b = map(int, input().split())
        x=x*b;
        y=y*a;
        if x<y:
            print("<")
        elif x>y:
            print(">")
        else:
            print("=")
except EOFError:
    pass


import math;print(math.gcd(int(input()), int(input())))
def gcd(a,b):
    while(a != b):
        if(a > b):
            a -= b
        else:
            b -= a
    return a
print(gcd(int(input()),int(input())))