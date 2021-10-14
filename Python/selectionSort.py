def selection_sort(array):
	
	for i in range(len(array)):
		# default index of array that has minimum value
		min_idx = i

		for j in range(i+1, len(array)):
			if array[min_idx] > array[j]:
				# Change index of minimum value if its greater than selected value
				min_idx = j

		# swap the values in the array		
		array[i], array[min_idx] = array[min_idx], array[i]


if __name__=="__main__":  
	# Driver code
	arr = [64, 25, 12, 22, 11]

	# Display original array
	print("Original Array:", end=" ")
	for i in range(len(arr)): 
		print(arr[i], end=" ")

	selection_sort(arr) 

	# Display sorted array
	print(), print("Sorted Array:", end=" ")
	for i in range(len(arr)):
		print(arr[i], end=" ")
