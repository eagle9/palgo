'''
Created on Dec 23, 2014

@author: XY1267

quicksort in place
https://www.cs.auckland.ac.nz/~jmor159/PLDS210/qsort1a.html

'''
import random
def sub_partition(array, start, end, idx_pivot):

    'returns the position where the pivot winds up'

    if not (start <= idx_pivot <= end):
        raise ValueError('idx pivot must be between start and end')

    array[start], array[idx_pivot] = array[idx_pivot], array[start]
    pivot = array[start]
    i = start + 1
    j = start + 1

    while j <= end:
        if array[j] <= pivot:
            array[j], array[i] = array[i], array[j]
            i += 1
        j += 1

    array[start], array[i - 1] = array[i - 1], array[start]
    return i - 1

#use two pointers for partition, i found this one is eastest to understand and remember
def ypartition(array,start,end,idx_pivot):
    if not ( start <= idx_pivot <= end):
        raise ValueError('idx_pivot out of start, end range')
    pivot = array[idx_pivot]
    
    array[start],array[idx_pivot] = array[idx_pivot],array[start]
    left, right = start, end
    
    while left < right:
        while array[left] <= pivot and left <= end: left += 1
        while array[right] > pivot and right >= start: right -= 1
        if (left < right): array[left], array[right] = array[right], array[left]
        
    array[start], array[right] = array[right], array[start]
    return right
    
def yquicksort(array=[12,4,5,6,7,3,1,15], start=0, end=None):
    if end == None:
        end = len(array) -1
    if end <= start: 
        return
    idx_pivot = random.randint(start,end)
    p = ypartition(array, start, end, idx_pivot)
    yquicksort(array,start,p-1)
    yquicksort(array,p+1,end)
    
def quicksort(array, start=0, end=None):

    if end is None:
        end = len(array) - 1

    if end - start < 1:
        return

    idx_pivot = random.randint(start, end)
    i = sub_partition(array, start, end, idx_pivot)
    #print array, i, idx_pivot
    quicksort(array, start, i - 1)
    quicksort(array, i + 1, end)