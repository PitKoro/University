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

h = (max(sample) - min(sample))/12 #разбили отрезок на 12 частей, получили шаг 0.264725


fi = 0.062
ni = 11 * 0.2*fi/0.498
print(ni) 
# Выдвинем гипотезу H0: распределение генеральной совокупности X подчинено нормальному 
# закону с параметрами a = 4.004820069204156 и σ = 0.5664344483986975 .

#Сортируем выборку чтобы найти повторяющиеся значения
sortedSample = sorted(sample)

# сортированный список в файл
sorted_f = open('sortedInput32.txt', 'w')
for item in sortedSample:
    sorted_f.write("%s\n" % item)
sorted_f.close()

# Создаем словарь (значение):(количество повторений)
dictDoubles = Counter(sortedSample) 
# Записываем словарь в файл
with open('doublesInput32.txt','w') as out:
    for key,val in dictDoubles.items():
        out.write('{}:{}\n'.format(key,val))

# Расчитываем теоритические частоты
dictKeys = dictDoubles.keys()
dictValues = dictDoubles.values()

ui = []
for key in dictDoubles:
    tmp = (float(key) - sampleMean)/standardDeviation
    ui.append(tmp)

fi=[] # список ϕ(ui)
for item in ui:
    tmp = (1/(sqrt(2*pi)))*(e ** (-(item**2)/2))
    fi.append(tmp)

theoretical_frequencies = []
for item in fi:
    tmp = size*h*item/standardDeviation
    theoretical_frequencies.append(tmp)

# Далее вычисляем Наблюдаемое значение критерия
index = 0
K = 0 # Значение Критерия
for val in dictDoubles.values():
    tmp = ((float(val) - float(theoretical_frequencies[index]))**2)/float(theoretical_frequencies[index])
    K += tmp
    index += 1

print(f'Критерий: {K}')