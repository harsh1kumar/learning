def fibonacci(n):
    if n<=1:
        return n
    
    return fibonacci(n-1) + fibonacci(n-2)

# 2 -> 2 -> 2^1
# 3 -> 2 + 1 = 3 -> 2^
# 4 -> 3 + 2 = 5
# 5 -> 5 + 3 = 8



def fibonacci_series_recursion(n):
    for i in range(n+1):
        print(fibonacci(i), end=" ")
    print("")


def fibonacci_series_simple(n):
    prev_to_last = 0
    last = 1

    print(prev_to_last, last, end=" ")
    for i in range(n-1):
        curr = prev_to_last + last
        print(curr, end=" ")
        prev_to_last = last
        last = curr
    print("")


def main():
    fibonacci_series_recursion(5)
    fibonacci_series_recursion(6)
    fibonacci_series_recursion(10)

    fibonacci_series_simple(5)
    fibonacci_series_simple(6)
    fibonacci_series_simple(10)

if __name__=="__main__":
    main()

# f(5) = 5
#   -> f(4) = 3
#       -> f(3) = 2
#       -> f(2) = 1
#   -> f(3) = 2
#       -> f(2) = 1
#          -> f(1) = 1
#          -> f(0) = 0
#       -> f(1) = 1
