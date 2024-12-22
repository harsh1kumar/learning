def reverse_number(n):
    rev = 0
    n_bck = n

    while n>0:
        r = n%10
        n //= 10
        rev = 10*rev + r
        
    print(f'n: {n_bck}, rev: {rev}')

def main():
    reverse_number(12345)
    reverse_number(7789)
    reverse_number(10400)


if __name__=="__main__":
    main()