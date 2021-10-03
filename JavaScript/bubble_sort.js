/**
* This file contains a three implementations of Bubble sort algorithm in JavaScript (ES5)
* The complexity of Bubble sort is O(n^2)
* From: Ben's blog http://blog.benoitvallon.com/sorting-algorithms-in-javascript/the-bubble-sort-algorithm/
*/

var array = [9, 2, 5, 6, 4, 3, 7, 10, 1, 8];
var arrayOrdered = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
var arrayReversed = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1];

/*
* Swap function helper
*/

function swap(array, i, j) {
  var temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

/*
* Basic Bubble sort algorithm (worst case)
*/

function bubbleSortBasic(array) {

  var temp;

  for(var i = 0; i < array.length; i++) {
    for(var j = 1; j < array.length; j++) {
      if( array[j - 1] > array[j] ) {
        //swap(array, j - 1, j);
        temp = array[j];
        array[j] = array[j - 1];
        array[j - 1] = temp;
      }
    }
  }
  return array;
}

console.log( bubbleSortBasic(array.slice()) );


/*
* A little bit enhanced bubble sort
*/

function bubbleSortEnhanced(array) {

  var swapped = true;
  var temp;

  do {
    swapped = false;
    for(var i = 0; i < array.length; i++) {
      if( array[i] !== undefined && array[i + 1] !== undefined && array[i] > array[i + 1] ) {
        //swap(array, i, i + 1);
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = true;
      }
    }
  } while(swapped)
  return array;
}

console.log( bubbleSortEnhanced(array.slice()) );


/*
* Another solution that reduces inner iterations and stops when array is actually sorted
*/

function bubbleSort(array) {

  var swapped = true,
      temp,
      j = 0;

  while(swapped) {
    swapped = false;
    j++;
    for (var i = 0; i < array.length - j; i++) {
      if(array[i] > array[i + 1]) {
        //swap(array, i, i + 1);
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = true;
      }
    }
  }
  return array;

}

console.log( bubbleSort(array.slice()) );



/*
* The last solution but with counters
*/


function bubbleSortCount(array) {

  var countOuter = 0;
  var countInner = 0;
  var countSwap = 0;

  var swapped = true,
      temp,
      j = 0;

  while(swapped) {
    countOuter++;
    swapped = false;
    j++;
    for (var i = 0; i < array.length - j; i++) {
      countInner++;
      if(array[i] > array[i + 1]) {
        //swap(array, i, i + 1);
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = true;
        countSwap++;
      }
    }
  }
  console.log('outer:', countOuter, 'inner:', countInner, 'swap:', countSwap);
  return array;

}


bubbleSortCount(array.slice());
bubbleSortCount(arrayOrdered.slice());
bubbleSortCount(arrayReversed.slice());
