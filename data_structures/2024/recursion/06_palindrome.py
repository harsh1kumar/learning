def is_palindrome(s: str) -> bool:
    # 6: 0 to 5 --> 0,1,2 - 3,4,5 -> 6/2
    # 7: 0 to 6 --> 0,1,2 - 3 - 4,5,6
    for i in range(int(len(s)/2)):
        if s[i] != s[-i-1]:
            return False
    
    return True

def main():
    print("ABCDCBA", is_palindrome("ABCDCBA"))
    print("ABCCBA", is_palindrome("ABCCBA"))
    print("ABCDEF", is_palindrome("ABCDEF"))
    
if __name__=="__main__":
    main()

