#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparisons = 0;
long long swaps = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

void bubblesort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if(arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void selectionsort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minidx = i;
        for(int j = i + 1; j < n; j++) {
            comparisons++;
            if(arr[j] < arr[minidx])
                minidx = j;
        }
        if(minidx != i)
            swap(&arr[i], &arr[minidx]);
    }
}

void insertionsort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0) {
            comparisons++;
            if(arr[j] > key) {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            }
            else
                break;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    for(int i = 0; i < n1; i++) 
        L[i] = arr[left + i];
    for(int i = 0; i < n2; i++) 
        R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        comparisons++;
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    
    while(i < n1) 
        arr[k++] = L[i++];
    while(j < n2) 
        arr[k++] = R[j++];
    free(L);
    free(R);
}

void mergesorthelper(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergesorthelper(arr, left, mid);
        mergesorthelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergesort(int arr[], int n) {
    mergesorthelper(arr, 0, n - 1);
}

void printarray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, choice;
    printf("enter number of elements (n): ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    int* original = (int*)malloc(n * sizeof(int));
    srand(time(NULL));
    printf("generating %d random numbers...\n\n", n);
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 1000 + 1;
        original[i] = arr[i];
    }
    printf("choose sorting algorithm:\n");
    printf("1. bubble sort\n");
    printf("2. selection sort\n");
    printf("3. insertion sort\n");
    printf("4. merge sort\n");
    printf("enter choice: ");
    scanf("%d", &choice);
    printf("\nbefore sorting:\n");
    if(n <= 50) {
        printarray(arr, n);
    } else {
        printf("(too many elements to display)\n");
    }
    comparisons = 0;
    swaps = 0;
    switch(choice) {
        case 1:
            printf("\nusing bubble sort:\n");
            bubblesort(arr, n);
            break;
        case 2:
            printf("\nusing selection sort:\n");
            selectionsort(arr, n);
            break;
        case 3:
            printf("\nusing insertion sort:\n");
            insertionsort(arr, n);
            break;
        case 4:
            printf("\nusing merge sort:\n");
            mergesort(arr, n);
            break;
        default:
            printf("invalid choice\n");
            return 1;
    }
    printf("\nafter sorting:\n");
    if(n <= 50)
        printarray(arr, n);
    else
        printf("(too many elements to display)\n");
    printf("\nstatistics:\n");
    printf("comparisons: %lld\n", comparisons);
    if(choice != 4)
        printf("swaps: %lld\n", swaps);
    free(arr);
    free(original);
    return 0;
}