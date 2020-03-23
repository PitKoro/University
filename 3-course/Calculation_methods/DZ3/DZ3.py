from functools import reduce # reduce() Применяет указанную функцию к элементам последовательности, сводя её к единственному значению.
from math import sqrt, pi

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

k = [2, 2.2, 2.4, 2.6, 2.8, 3, 3.2, 3.4, 3.6, 3.8, 4, 4.2, 5.6] #разбили отрезок на 12 частей

# Выдвинем гипотезу H0: распределение генеральной совокупности X подчинено нормальному 
# закону с параметрами a = 4.004820069204156 и σ = 0.5664344483986975 .

for N in 