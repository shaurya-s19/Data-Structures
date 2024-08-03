#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    
    do {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quicksort(int arr[], int low, int high) {
    int partitionIndex; // index of pivot after partition
    
    if (low < high) {
        partitionIndex = partition(arr, low, high);
        quicksort(arr, low, partitionIndex - 1);  // sort left sub-array
        quicksort(arr, partitionIndex + 1, high); // sort right sub-array
    }
}

bool isAnagram(char* s, char* t) {
    size_t lenS = strlen(s);
    size_t lenT = strlen(t);
    
    // Check if lengths are different
    if (lenS != lenT) {
        return false;
    }
    
    // Allocate memory dynamically
    int* arr1 = (int*)malloc(lenS * sizeof(int));
    int* arr2 = (int*)malloc(lenT * sizeof(int));
    
    if (arr1 == NULL || arr2 == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        return false;
    }
    
    for (size_t i = 0; i < lenS; i++) {
        arr1[i] = (int)s[i];
        arr2[i] = (int)t[i];
    }
    
    quicksort(arr1, 0, lenS - 1);
    quicksort(arr2, 0, lenT - 1);
    
    for (size_t i = 0; i < lenS; i++) {
        if (arr1[i] != arr2[i]) {
            free(arr1);
            free(arr2);
            return false;
        }
    }
    
    free(arr1);
    free(arr2);
    return true;
}
