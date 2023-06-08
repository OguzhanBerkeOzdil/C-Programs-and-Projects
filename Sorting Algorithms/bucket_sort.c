#include "bucket_sort.h"

void insertion_sorting(int arr[], int n) {
    for (int step = 1; step < n; step++) {
        int key = arr[step];
        int j = step - 1;

        while (key < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Bucket sort funciton definiton
void bucket_sort(int arr[], int n, int max_value) {
    int bucket[max_value + 1];
    for (int i = 0; i <= max_value; i++) {
        bucket[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_value; i++) {
        while (bucket[i] > 0) {
            arr[index++] = i;
            bucket[i]--;
        }
    }
}