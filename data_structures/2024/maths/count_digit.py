import numpy as np

def count_digits(n):
    i = 0
    while True:
        x = 10**i
        if n//x==0:
            break
        i += 1

    print(f'n={n}, digits={i}, digit_optimal={int(np.log10(n))+1}')

def main():
    count_digits(10)
    count_digits(1234)
    count_digits(45345)

if __name__=="__main__":
    main()