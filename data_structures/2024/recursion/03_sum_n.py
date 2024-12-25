def sum_n(n):
    if n==1:
        return 1

    return n + sum_n(n-1)

print(sum_n(10))
print(sum_n(100))
