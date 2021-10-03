def counting_sort(arr, exp1):

    n = len(arr)

    output = [0] * (n)

    count = [0] * (10)

    for i in range(0, n):
        index = (arr[i]/exp1)
        count[int((index) % 10)] += 1

    for i in range(1, 10):
        count[i] += count[i-1]

    i = n-1
    while i >= 0:
        index = (arr[i]/exp1)
        output[count[int((index) % 10)] - 1] = arr[i]
        count[int((index) % 10)] -= 1
        i -= 1

    i = 0
    for i in range(0, len(arr)):
        arr[i] = output[i]


def radixSort(arr):

    max1 = max(arr)

    exp = 1
    while max1/exp > 0:
        counting_sort(arr, exp)
        exp *= 10


arr = [100, 96, 43, 56, 67, 32, 875, 24342, 7665, 5378755]
radixSort(arr)

for i in range(len(arr)):
    print(arr[i]),

   # code contributed by vibhor agarwal
