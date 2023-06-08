#include "merge_sort.h"

void merge(int arr[], int left[], int leftSize, int right[], int rightSize, int sorted[]) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            sorted[k++] = left[i++];
        } else {
            sorted[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        sorted[k++] = left[i++];
    }

    while (j < rightSize) {
        sorted[k++] = right[j++];
    }
}

// Merge sort function definition
void merge_sort(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }

    merge_sort(left, mid);
    merge_sort(right, n - mid);

    merge(arr, left, mid, right, n - mid, arr);
}
