from functools import reduce # reduce() Применяет указанную функцию к элементам последовательности, сводя её к единственному значению.
from math import sqrt

def readFromFile(filename):
    with open(filename, 'r') as f:
        s = f.read()
    a = s.split('\n')
    return [float(e) for e in a]

sample = readFromFile('input32.txt')
size = len(sample) # (1) Объем выборки
print('(1) Объем выборки: ' + str(size))
sampleMean = sum(sample)/size # (2) Выборочное среднее
print('(2) Выборочное среднее: ' + str(sampleMean))

sampleVariance = (reduce(lambda acc, val: acc + val**2, sample))/size - sampleMean**2 # Выборочная дисперсия

standardDeviation = sqrt(sampleVariance)# (3) Cреднеквадратичное отклонение 
print('(3) Cреднеквадратичное отклонение: ' + str(standardDeviation))

eps = 3*sqrt(sampleVariance) / sqrt(size) # (4) 99%-доверительный интервал для мат. ожидания
print('(4) 99%-доверительный интервал для мат. ожидания: ' + str(eps))


# 5 пункт пока хз как делать


input("Press F to end...\n")