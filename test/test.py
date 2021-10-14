import sys
from pathlib import *
sys.path.insert(0, str(Path(__file__).resolve().parent.parent))

from Python import bubbleSort, insertionSort, mergeSort, quickSort, radixSort, selection_sort, shell_sort, sleepSort

sort_key_map = {
    'bubbleSort' : bubbleSort,
    'insertionSort' : insertionSort,
    'mergeSort' : mergeSort,
    'quickSort' : quickSort,
    'radixSort' : radixSort,
    'selection_sort' : selection_sort,
    'shell_sort' : shell_sort,
    # 'sleepSort' : sleepSort, 
}

unsorted_list = [12, 38, 4, 28, 65, 19, 7, 83, 73, 53, 49, 72, 26, 10, 47, 32, 25, 15, 55, 3, 36, 84, 78, 1, 75, 33, 90, 45, 58, 87, 21, 22, 89, 23, 63, 51, 9, 13, 82, 57, 17, 77, 66, 37, 94, 41, 74, 96, 43, 70]
sorted_list = sorted(unsorted_list)
passed = 0

for key in sort_key_map:
    try:
        arr = unsorted_list.copy()
        sort_key_map[key](arr)
        if arr == sorted_list:
            print(f'{key} passed ✔')
            passed += 1
        else:
            print(f'{key} failed ❌')
    except Exception as e:
        print(e)
        print(f'{key} failed')

print(f'{passed}/{len(sort_key_map)} passed')