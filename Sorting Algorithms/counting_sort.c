#include "counting_sort.h"

// Counting sort function definiton
void counting_sort(int arr[], int n, int range) {
    int *count = (int *)calloc(range, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    // Step 1: Create the counting array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 2: Update the count array
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Step 3: Create the sorted array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 4: Copy the sorted array to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}