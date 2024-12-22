##############################################
# Questions: https://takeuforward.org/strivers-a2z-dsa-course/must-do-pattern-problems-before-starting-dsa/
##############################################

def pat12(row):
    for i in range(row):
        for j in range(i+1):
            print(j+1, end="")

        
        for j in range(2*(row-i-1)):
            print(" ", end="")
        
        for j in range(i+1, 0, -1):
            print(j, end="")
        print("")

def pat13(row):
    x = 1
    for i in range(row):
        for j in range(i+1):
            print(x, end=" ")
            x += 1
        print("")

def pat14(row):
    for i in range(row):
        c = 65
        for j in range(i+1):
            print(chr(c), end="")
            c += 1
        print("")

def pat15(row):
    for i in range(row, 0, -1):
        c = 65
        for j in range(i):
            print(chr(c), end="")
            c += 1
        print("")

def pat16(row):
    c = 65
    for i in range(row):
        for j in range(i+1):
            print(chr(c), end="")
        print("")
        c += 1

def pat17(row):
    for i in range(row):
        for j in range(row-1-i):
            print(" ", end="")
        
        c = 65
        for j in range(2*i+1):
            print(chr(c), end="")
            if j>i-1:
                c -= 1
            else:
                c += 1

        for j in range(row-1-i):
            print(" ", end="")
        
        print("", end="\n")


def pat18(row):
    for i in range(row):
        c = 65 + row - i - 1
        for i in range(i+1):
            print(chr(c), end="")
            c += 1
        print("")

def pat19(row):
    for i in range(row):
        for j in range(row-i):
            print("*", end="")
        
        for j in range(i):
            print(2*" ", end="")
        
        for j in range(row-i):
            print("*", end="")

        print("")
    
    
    for i in range(row):
        for j in range(i+1):
            print("*", end="")
        
        for j in range(row-i-1):
            print(2*" ", end="")
        
        for j in range(i+1):
            print("*", end="")

        print("")
        
def pat21(row):
    for i in range(row):
        for j in range(row):
            if i==0 or i==row-1 or j==0 or j==row-1:
                print("*", end="")
            else:
                print(" ", end="")
        print("")

def pat22(row):
    for i in range(2*row-1):
        for j in range(2*row-1):
            x = i
            if i>=row:
                x = 2*(row-1)-i
            y = j
            if j>row:
                y = 2*(row-1)-j
            
            print(row-min(x, y), end="")
        print("")

def main():
    row = 6
    pat22(row)


if __name__ == "__main__":
    main()