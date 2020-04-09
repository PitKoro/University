from math import pi

def factorial(n):
    if n == 0:
        return 1
    return factorial(n-1) * n


def fTeylor(x):
    return (1/factorial(3)) - ((x**2)/factorial(5)) + ((x**4)/factorial(7)) - ((x**6)/factorial(9))

def integralTeylor(start):
    return (start/factorial(3)) - ((start**3)/(factorial(5)*3)) + ((start**5)/(factorial(7)*5)) - ((start**7)/(factorial(9)*7))