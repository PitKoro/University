# импортируем модули
from math import  sin, pi, exp
import numpy as np
import matplotlib.pyplot as plt
from scipy import integrate

def f(x):
    if x == 0:
        return 1.0
    return (x-sin(x))/x**3

#------------------------------------------------------Вычисление интеграла-------------------------------------------------
l = integrate.quad(f, 0, pi)
Integral = l[0] + l[1]
print(Integral)
#---------------------------------------------------------------------------------------------------------------------------

#-----------------------------------------------------Рисуем график f(x)----------------------------------------------------
#http://itrobo.ru/programmirovanie/python/grafiki-funkcii-i-poverhnostei-v-python-.html
x = np.linspace(-10, 10,1000) # создаём область, в которой будет отображаться график
f_y = [f(x) for x in x]
plt.plot(x, f_y, label='f')
plt.legend()
plt.show()
#---------------------------------------------------------------------------------------------------------------------------
