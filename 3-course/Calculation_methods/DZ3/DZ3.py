from functools import reduce # reduce() Применяет указанную функцию к элементам последовательности, сводя её к единственному значению.
from math import sqrt

def readFromFile(filename):
    with open(filename, 'r') as f:
        s = f.read()
    a = s.split('\n')
    return [float(e) for e in a]

sample = readFromFile('input32.txt')
#print(f'min: {min(sample)}\nmax: {max(sample)}')
size = len(sample) # (1) Объем выборки
print(f'(1) Объем выборки: {size}')
sampleMean = sum(sample)/size # (2) Выборочное среднее
print(f'(2) Выборочное среднее: {sampleMean}')

sampleVariance = (reduce(lambda acc, val: acc + val**2, sample))/size - sampleMean**2 # Выборочная дисперсия

standardDeviation = sqrt(sampleVariance)# (3) Cреднеквадратичное отклонение 
print(f'(3) Cреднеквадратичное отклонение: {standardDeviation}')

eps = 3*sqrt(sampleVariance) / sqrt(size) # (4) 99%-доверительный интервал для мат. ожидания
print(f'(4) 99%-доверительный интервал для мат. ожидания: ({-eps} ; {eps})')


# 5 пункт пока хз как делать

k = [2, 2.2, 2.5, 2.9, 3.5, 3.6, 4, 5, 5.2, 5.4, 5.5, 5.7, 6] #разбили отрезок на 12 частей
