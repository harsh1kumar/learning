def print_name(name, n):
    if n==0:
        return

    print(name)
    return print_name(name, n-1)

print_name("Harsh", 5)