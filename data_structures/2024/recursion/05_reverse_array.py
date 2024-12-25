def reverse_array(arr):
    if len(arr)==1:
        print(arr[0])
        return

    print(arr[-1], end=" ")
    return reverse_array(arr[0:-1])

reverse_array([5,4,3,2,1])