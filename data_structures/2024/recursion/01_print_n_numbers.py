def print_n(s, n):
    if s>n:
        return
    print(s)
    return print_n(s+1, n)


print_n(0, 10)

