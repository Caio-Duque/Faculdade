def partition(array, start, end):
    pivot = array[start]
    low = start + 1
    high = end

    while True:

        while low <= high and array[high] >= pivot:
            high = high - 1
        while low <= high and array[low] <= pivot:
            low = low + 1

        if low <= high:

            array[low], array[high] = array[high], array[low]

        else:

            break

    array[start], array[high] = array[high], array[start]
    return high

def quick_sort(array, start, end):
    if start >= end:
        return

    p = partition(array, start, end)
    quick_sort(array, start, p-1)
    quick_sort(array, p+1, end)

def bubbleSort(array):
    for passnum in range(len(array)-1, 0, -1):
        for i in range(passnum):
            if array[i]>array[i+1]:
                temp = array[i]
                array[i] = array [i+1]
                array[i+1] = temp

# Gerando 100 numeros inteiros em um intervalo de 0 a 1000. 

import random

array = []
for i in range(0, 100):
    array.append(random.randint(0,1000))

import time

print('lista desordenada')
print(array)

## ordenando com quicksort

inicio = time.time()
quick_sort(array, 0, len(array) - 1)
print('lista ordenada no usando o quick_sort')
print(array)

fim = time.time()
print('tempo de execucao no quick_sort')
print(fim - inicio)

## ordenando com bubblesort

inicio = time.time()
bubbleSort(array)
print('lista ordenada no usando o quick_sort')
print(array)

fim = time.time()
print('tempo de execucao no bubbleSort')
print(fim - inicio)