def merge_sort(l, r):
    if l >= r:
        return
    m = (l + r) >> 1
    
    merge_sort(l, m)
    merge_sort(m + 1, r)

    ls = m - l + 1; rs = r - m
    L = arr[l : m + 1]
    R = arr[m + 1 : r + 1]

    i = j = 0; k = l
    while i < ls and j < rs:
        if L[i] <= R[j]: arr[k] = L[i]; i += 1
        else: arr[k] = R[j]; j += 1
        k += 1
    while i < ls: 
        arr[k] = L[i]; i += 1; k += 1
    while j < rs: 
        arr[k] = R[j]; j += 1; k += 1

arr = [8, 3, 4, 6, 7, 1, 2]

merge_sort(0, len(arr) - 1)

print(arr)