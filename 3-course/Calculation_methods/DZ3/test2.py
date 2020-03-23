from functools import reduce # reduce() Применяет указанную функцию к элементам последовательности, сводя её к единственному значению.
from math import sqrt, pi, e
from collections import Counter

def readFromFile(filename):
    with open(filename, 'r') as f:
        s = f.read()
    a = s.split('\n')
    return [float(e) for e in a]

sample = readFromFile('input32.txt')
print(f'min: {min(sample)}\nmax: {max(sample)}')
size = len(sample) # (1) Объем выборки
print(f'(1) Объем выборки: {size}')
sampleMean = sum(sample)/size # (2) Выборочное среднее
print(f'(2) Выборочное среднее: {sampleMean}')

sampleVariance = (reduce(lambda acc, val: acc + val**2, sample))/size - sampleMean**2 # Выборочная дисперсия

standardDeviation = sqrt(sampleVariance)# (3) Cреднеквадратичное отклонение 
print(f'(3) Cреднеквадратичное отклонение: {standardDeviation}')

eps = 3*sqrt(sampleVariance) / sqrt(size) # (4) 99%-доверительный интервал для мат. ожидания
print(f'(4) 99%-доверительный интервал для мат. ожидания: ({-eps} ; {eps})')


# По критерию хи квадрат проверить гипотезу что распределение нормальное
# https://www.matburo.ru/Examples/Files/ms_pg_3.pdf

k = [0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9, 2.1, 2.3] # Разбили на 12 частей, шаг 0.275
h = 0.2
# Выдвинем гипотезу H0: распределение генеральной совокупности X подчинено нормальному 
# закону с параметрами a = 4.004820069204156 и σ = 0.5664344483986975 .

n_k = [7, 9, 28, 27, 30, 26, 21, 25, 22, 9, 5] 


size = 209
sampleMean = 1.261
standardDeviation = 0.498
# Расчитываем теоритические частоты
ui = []
tmp = 0
for i in range(0, len(k)-1):
    tmp = (k[i] - sampleMean)/standardDeviation
    ui.append(tmp)


fi=[] # список ϕ(ui)
tmp = 0
for i in range(0, len(k)-1):
    tmp = (1/(sqrt(2*pi)))*(e ** (-(ui[i]**2)/2))
    fi.append(tmp)


theoretical_frequencies = []
tmp = 0
for i in range(0,len(fi)-1):
    tmp = size*h*fi[i]/standardDeviation
    theoretical_frequencies.append(tmp)

# Далее вычисляем Наблюдаемое значение критерия
chiSquared = 0
for theoretical_frequencies, num  in zip(theoretical_frequencies, n_k):
    chiSquared += ((num - theoretical_frequencies)**2) / theoretical_frequencies

print(f'Критерий: {chiSquared}')