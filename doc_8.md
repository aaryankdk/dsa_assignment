# Program 8

## Data Structures

The program uses dynamically allocated arrays to handle any size input:
- `arr[]` - the array being sorted
- `original[]` - backup copy of the original array
- Global counters `comparisons` and `swaps` track algorithm performance

## Functions

### swap(int* a, int* b)
Swaps two values and increments the swap counter.

### bubblesort(int arr[], int n)
Repeatedly steps through the list comparing adjacent elements and swapping them if they're in the wrong order. Larger values "bubble" toward the end. Time complexity is O(n²).

### selectionsort(int arr[], int n)
Finds the minimum element in the unsorted portion and swaps it with the first unsorted element. Repeats until everything is sorted. Also O(n²) but typically does fewer swaps than bubble sort.

### insertionsort(int arr[], int n)
Builds the sorted list one element at a time by inserting each new element into its proper position. Works well on small or nearly-sorted data. O(n²) worst case but can be O(n) on already sorted data.

### merge(int arr[], int left, int mid, int right)
Merges two sorted subarrays into one. Creates temporary arrays for the merge operation and counts comparisons.

### mergesorthelper(int arr[], int left, int right)
Recursive helper that divides the array in half until reaching single elements.

### mergesort(int arr[], int n)
Divide and conquer algorithm - splits the array recursively and merges the sorted pieces. Guaranteed O(n log n) time complexity.

### printarray(int arr[], int n)
Displays the array, but only if it has 50 or fewer elements to avoid cluttering the output.

## Main Method

Asks for how many random numbers to generate (between 1 and 1000). Shows a menu of sorting algorithms and lets you pick one. Displays the unsorted array (if small enough), sorts it using your chosen algorithm, and shows the sorted result along with statistics on comparisons and swaps.

## Sample Output

```
enter number of elements (n): 10
generating 10 random numbers...

choose sorting algorithm:
1. bubble sort
2. selection sort
3. insertion sort
4. merge sort
enter choice: 1

before sorting:
234 567 123 890 456 234 678 345 901 123 

using bubble sort...

after sorting:
123 123 234 234 345 456 567 678 890 901 

statistics:
comparisons: 45
swaps: 18
```