#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minheapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] < arr[smallest])
        smallest = left;
    if(right < n && arr[right] < arr[smallest])
        smallest = right;
    if(smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minheapify(arr, n, smallest);
    }
}

void maxheapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        maxheapify(arr, n, largest);
    }
}

void buildminheap(int arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--)
        minheapify(arr, n, i);
}

void buildmaxheap(int arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--)
        maxheapify(arr, n, i);
}

void printarray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("enter number of elements: ");
    scanf("%d", &n);
    int arr[n], minarr[n], maxarr[n];
    printf("enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        minarr[i] = arr[i];
        maxarr[i] = arr[i];
    }
    printf("\noriginal array: ");
    printarray(arr, n);
    buildminheap(minarr, n);
    printf("min heap: ");
    printarray(minarr, n);
    buildmaxheap(maxarr, n);
    printf("max heap: ");
    printarray(maxarr, n);
    return 0;
}