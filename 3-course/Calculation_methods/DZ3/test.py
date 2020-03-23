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

k = [2.3, 2.575, 2.85, 3.125, 3.4, 3.675, 3.95, 4.225, 4.5, 4.775, 5.05, 5.325, 5.6 ] # Разбили на 12 частей, шаг 0.275
h = 0.275
# Выдвинем гипотезу H0: распределение генеральной совокупности X подчинено нормальному 
# закону с параметрами a = 4.004820069204156 и σ = 0.5664344483986975 .

n_k = [0 for i in range(len(k) - 1)] #Количество вхождений в интервале

for item in sample:
    for i in range(1, len(k)):
        if item <= k[i]:
            n_k[i-1]+=1
            break

print(n_k)

# Расчитываем теоритические частоты
ui = []
for item in k:
    tmp = (float(item) - sampleMean)/standardDeviation
    ui.append(tmp)

fi=[] # список ϕ(ui)
for item in ui:
    tmp = (1/(sqrt(2*pi)))*(e ** (-(item**2)/2))
    fi.append(tmp)

theoretical_frequencies = []
h = 0.2
for item in fi:
    tmp = size*h*item/standardDeviation
    theoretical_frequencies.append(tmp)

# Далее вычисляем Наблюдаемое значение критерия
index = 0
K = 0 # Значение Критерия
for val in n_k:
    tmp = ((float(val) - float(theoretical_frequencies[index]))**2)/float(theoretical_frequencies[index])
    K += tmp
    index += 1

print(f'Критерий: {K}')