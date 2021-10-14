def insertionSort(arr):
    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):
        key = arr[i]

        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i-1
        while j >=0 and key < arr[j] :
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key 

if __name__=="__main__":  
    # Driver code to test above
    arr = [12, 11, 13, 5, 6]

    # Display original array
    print("Original Array:", end=" ")
    for i in range(len(arr)): 
        print(arr[i], end=" ")

    insertionSort(arr)

    # Display sorted array
    print(), print("Sorted Array:", end=" ")
    for i in range(len(arr)):
        print(arr[i], end=" ")
