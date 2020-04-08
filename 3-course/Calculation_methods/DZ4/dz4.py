# импортируем модули
from math import  fsum, sin, cos, pi
import matplotlib.pyplot as plt
import numpy as np
from scipy import integrate


def f(x):
    if x == 0:
        return 1.0
    return (x-sin(x))/x**3

def LagrangePolynomial(x, xNodes, yNodes):
    def basicPolynomials(i):
        if i == 0:
            return ((x - xNodes[1])/(xNodes[0]-xNodes[1]))*((x - xNodes[2])/(xNodes[0]-xNodes[2]))
        elif i == 1:
            return ((x - xNodes[0])/(xNodes[1]-xNodes[0]))*((x - xNodes[2])/(xNodes[1]-xNodes[2]))
        elif i == 2:
            return ((x - xNodes[0])/(xNodes[2]-xNodes[0]))*((x - xNodes[1])/(xNodes[2]-xNodes[1]))
    
    LagrangePolynomial = [yNodes[i]*basicPolynomials(i) for i in range(0,3)]    
    return fsum(LagrangePolynomial)

#------------------------------------------------------Вычисление интеграла-------------------------------------------------
#https://www.youtube.com/watch?v=Ydt6JMVjf1g
l = integrate.quad(f, 0, pi)
Integral = l[0] + l[1]
print(Integral)
print(
    f'Интеграл от f на [0, pi] = {Integral}'
)
#---------------------------------------------------------------------------------------------------------------------------

#------------------------------------------------------Ищем узлы Чебышева-------------------------------------------------
#https://ru.wikipedia.org/wiki/%D0%A3%D0%B7%D0%BB%D1%8B_%D0%A7%D0%B5%D0%B1%D1%8B%D1%88%D1%91%D0%B2%D0%B0
xNodes = [] #Список узлов (только координата x)
yNodes = [] #Список узлов (только координата y)
nNodes = 3 #Количество узлов
xNodes = [(pi/2) + (pi/2)*cos(pi*((2*k - 1)/(2*nNodes))) for k in range(1,4)]    
#print(xNodes)
yNodes = [f(x) for x in xNodes]
#print(yNodes)

#---------------------------------------------------------------------------------------------------------------------------

#-----------------------------------------------------Рисуем график f(x)----------------------------------------------------
#http://itrobo.ru/programmirovanie/python/grafiki-funkcii-i-poverhnostei-v-python-.html
x = np.linspace(-0.00001, pi) # создаём область, в которой будет отображаться график
f_y = [f(x) for x in x]
S_y = [LagrangePolynomial(x, xNodes, yNodes) for x in x]
plt.plot(x, f_y, label='f')
plt.plot(x, S_y, label='S')
plt.legend()
plt.show()
#---------------------------------------------------------------------------------------------------------------------------
