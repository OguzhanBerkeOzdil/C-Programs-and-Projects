#include "radix_sort.h"

// Function helper: Finds the largest element of the given array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function helper: Sorts the given array by counting on the count array
void count_sort(int arr[], int n, int exp) {
    const int BASE = 10;
    int output[n];
    int* count = (int*)calloc(BASE, sizeof(int)); // calloc ile count dizisi oluşturuldu

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % BASE]++;
    }

    for (int i = 1; i < BASE; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
        count[(arr[i] / exp) % BASE]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count); // count dizisi serbest bırakıldı
}

// Radix Sort function definition
void radix_sort(int arr[], int n) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        count_sort(arr, n, exp);
    }
}
