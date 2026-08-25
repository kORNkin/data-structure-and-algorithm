def bound_search(tar, compare):
    l, r = 0, len(arr)
    while l < r:
        m = (l + r) >> 1
        if compare(tar, arr[m]):
            r = m
        else:
            l = m + 1
    return l

lower = lambda tar, mid: tar <= mid
upper = lambda tar, mid: tar < mid

arr = [1, 2, 2, 2, 3, 5, 7, 8, 10]
print(f"lower bound of finding 2 is {bound_search(2, lower)}")
print(f"upper bound of finding 2 is {bound_search(2, upper)}")