def upper_bound(tar):
    l, r = 0, len(arr)
    while l < r:
        m = (l + r) >> 1
        if tar < arr[m]:
            r = m
        else:
            l = m + 1
    return l

arr = [1, 2, 2, 2, 3, 5, 7, 8, 10]
print(upper_bound(2))