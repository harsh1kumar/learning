def check_palindrome(n):
    n_bck = n
    rev = 0
    while n>0:
        r = n%10
        n //= 10
        rev = 10*rev + r
    
    print(f'n={n_bck}, Palindrome:{n_bck == rev}')
    


check_palindrome(12131)
check_palindrome(121)
check_palindrome(1331)
check_palindrome(4554)
check_palindrome(7789)
check_palindrome(1001)
