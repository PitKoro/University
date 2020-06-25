from math import sin, cos, sqrt, pi
from functools import reduce

from matplotlib import pyplot as plt

A = [1, 2]
G = 9.81
k = 0.05
m = 1
OMEGA = sqrt(G)

def getF(a):
    def f(t, fi, derivative_fi):
        return -G*sin(fi) + a*sin(OMEGA*t)*cos(fi) - (k*derivative_fi)/m
    return f

def solution(f, n):
    step = 25/n
    prev_t = t = 0
    prev_z = z = 0
    prev_fi = fi = 0
    

    result = [(t, fi)]

    for i in range(1, n+1):
        t = prev_t + step

        temp_z = prev_z + step*f(prev_t, prev_fi, prev_z)
        temp_fi = prev_fi + step*prev_z

        z = prev_z + step*(f(prev_t, prev_fi, prev_z) + f(t, temp_fi, temp_z))/2
        fi = prev_fi + step*(prev_z + temp_z)/2

        prev_t = t
        prev_z = z
        prev_fi = fi
        result.append((t, fi))
    
    return result

for a in A:
    result = []
    f = getF(a)
    n = 2

    while(True):
        fi1 = solution(f, n)
        fi2 = solution(f, 2*n)
        ok = True

        alpha = abs(fi1[-1][1] - fi2[-1][1])/3

        for i in range (n, -1, -1):
            err = abs(fi1[i][1] - fi2[2*i][1])/3
            if sqrt(2*abs(1-cos(err))) >= 0.001:
                ok = False
                break

        if ok:
            result = fi2
            break

        n = 2*n
    

    x, y = [], []
    for point in result:
        x.append(point[0])
        y.append(point[1])

    plt.plot(x, y)
    print (
        f'A = {a}\n'
        f'|Fi_max| = {reduce(lambda acc, val: abs(val) if abs(val) > acc else acc, y, abs(y[0])):5.2f}'
    )
    plt.show()