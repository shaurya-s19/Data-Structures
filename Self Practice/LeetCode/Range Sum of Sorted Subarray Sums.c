#include <stdio.h>
#include <stdlib.h>

void quicksort(int[], int, int);
int partition(int[], int, int);

int rangeSum(int* nums, int numSize , int n, int left, int right) {
    // Calculate the total number of possible subarrays
    numSize = n * (n + 1) / 2;
    
    // Allocating memory for the array of subarray sums
    int* sum_arr = (int*)malloc(numSize * sizeof(int));
    if (sum_arr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Populate the array with sums of all subarrays
    int index = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            sum_arr[index++] = sum;
        }
    }

    // Sort the array of sums
    quicksort(sum_arr, 0, numSize - 1);

    // Validate the range
    if (left < 1 || right > numSize || left > right) {
        fprintf(stderr, "Invalid range: left=%d, right=%d\n", left, right);
        free(sum_arr);
        exit(EXIT_FAILURE);
    }

    // Compute the sum of the specified range
    long long sum_ = 0; // Use long long to prevent overflow
    for (int i = left - 1; i < right; i++) {
        sum_ += sum_arr[i];
    }

    free(sum_arr); // Free allocated memory

    const int M = 1000000007;
    return (int)(sum_ % M); // Return the result modulo M
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
