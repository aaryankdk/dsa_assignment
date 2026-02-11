# Program 6

## Data Structures

The program represents heaps as arrays. In this representation:
- Parent of element at index i is at position (i-1)/2
- Left child of i is at 2*i+1
- Right child of i is at 2*i+2

## Functions

### swap(int* a, int* b)
Exchanges two values.

### minheapify(int arr[], int n, int i)
Makes sure the min heap property holds at a given index. Compares the node with its children and swaps with the smaller child if needed. Recursively fixes any violations down the tree.

### maxheapify(int arr[], int n, int i)
Same idea as minheapify but maintains the max heap property. Swaps with the larger child when necessary.

### buildminheap(int arr[], int n)
Converts an unsorted array into a min heap. Starts from the last non-leaf node and works upward, calling minheapify on each. The smallest element ends up at the root.

### buildmaxheap(int arr[], int n)
Converts an unsorted array into a max heap. Uses the same bottom-up approach but ensures the largest element is at the root.

### printarray(int arr[], int n)
Displays the array.

## Main Method

Asks for the number of elements and reads them from the user. Creates two copies of the input array - one gets turned into a min heap, the other into a max heap. Shows all three versions: original, min heap, and max heap.

## Sample Output

```
enter number of elements: 7
enter 7 elements:
4
10
3
5
1
8
6

original array: 4 10 3 5 1 8 6 
min heap: 1 4 3 5 10 8 6 
max heap: 10 5 8 4 1 3 6
```