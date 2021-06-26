def partition(arr,low,high):
    pivot = arr[high]
    for j in range(low,high):
        i = low - 1 #index of smaller element than pivot
        if arr[j] <= pivot:
            i+=1
            arr[i],arr[j] = arr[j],arr[i]
    arr[i+1],arr[high] = arr[high],arr[i+1]
    return i+1 #index of settled pivot

def quickSort(arr,low,high):
    if (low < high): #recursion exit condition
        #partition arr into low,pi-1 and pi+1,high
        pi = partition(arr,low,high)
        quickSort(arr,low,pi-1)
        quickSort(arr,pi+1,high)

arr = [10, 7, 8, 9, 1, 5]
print 'before:',arr
quickSort(arr,0,len(arr)-1)
print 'after:',arr

