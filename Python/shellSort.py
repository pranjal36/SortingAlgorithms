def shell_sort(array, func=lambda x : x//2):
    N = len(arr)
    gap = func(N)

    # sort the array at specifics gaps until gap is not zero
    while gap > 0:

        #insertion sort routine 
        for i in range(gap,N):

            temp = arr[i]

            j = i
            while  j >= gap and arr[j-gap] >temp:
                arr[j] = arr[j-gap]
                j -= gap

            arr[j] = temp
        gap = func(gap)



# Driver code
arr = [64, 25, 12, 22, 11]

# Display original array
print("Original Array:", end=" ")
for i in range(len(arr)): 
    print(arr[i], end=" ")

shell_sort(arr) 

# Display sorted array
print(), print("Sorted Array:", end=" ")
for i in range(len(arr)):
    print(arr[i], end=" ")
