const bubble_sort = require('../../JavaScript/bubble_sort');
const heapsort = require('../../JavaScript/heapsort');
const insertionSort = require('../../JavaScript/insertionSort');
const MergeSort = require('../../JavaScript/MergeSort');
const odd_even_sort = require('../../JavaScript/odd_even_sort');
const selectionSort = require('../../JavaScript/selectionSort');
const QuickSort = require('../../JavaScript/QuickSort');

sort_key_map = {
    'bubble_sort': bubble_sort.bblSort,
    'heap_sort': heapsort.heapSort,
    'insertion_sort': insertionSort.insertionSort,
    'merge_sort': MergeSort.mergeSort,
    'odd_even_sort': odd_even_sort.oddEvenSort,
    'quick_sort': QuickSort.quickSort,
    'selection_sort': selectionSort.selectionSort,
}


var unsorted_list = [12, 38, 4, 28, 65, 19, 7, 83, 73, 53, 49, 72, 26, 10, 47, 32, 25, 15, 55, 3, 36, 84, 78, 1, 75, 33, 90, 45, 58, 87, 21, 22, 89, 23, 63, 51, 9, 13, 82, 57, 17, 77, 66, 37, 94, 41, 74, 96, 43, 70];
var sorted_list = [...unsorted_list];
var passed = 0;
sorted_list.sort(function(a, b) { return a - b });

function arrayEquals(a, b) {
    return Array.isArray(a) &&
        Array.isArray(b) &&
        a.length === b.length &&
        a.every((val, index) => val === b[index]);
}

for (const key in sort_key_map) {
    try {
        var arr = [...unsorted_list];
        sort_key_map[key](arr);
        if (arrayEquals(arr, sorted_list)) {
            console.log(`${key} passed ✔`);
            passed += 1
        } else {
            console.log(`${key} failed ❌`);
        }
    } catch (e) {
        console.log(e);
        console.log(`${key} failed ❌`);
    }
}