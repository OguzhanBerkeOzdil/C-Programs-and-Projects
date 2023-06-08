#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"
#include "radix_sort.h"
#include "counting_sort.h"
#include "bucket_sort.h"
#include "shell_sort.h"

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    srand(time(0)); // a function used to generate random numbers
    int n, choice;

    printf("Which sorting algorithm would you like to choose?\n");
    printf("1:  Bubble Sort\n");
    printf("2:  Insertion Sort\n");
    printf("3:  Selection Sort\n");
    printf("4:  Merge Sort\n");
    printf("5:  Quick Sort\n");
    printf("6:  Heap Sort\n");
    printf("7:  Radix Sort\n");
    printf("8:  Counting Sort\n");
    printf("9:  Bucket Sort\n");
    printf("10: Shell Sort\n");
    printf("--------------------\n");
    printf("11: Select this option to close the program: ");

    while (1) {
        if (scanf("%d", &choice) != 1 || (choice < 1 || choice > 11)) {
            printf("Invalid selection! Please enter a number from 1-11.\n");
            while (getchar() != '\n'); // If the user does not enter an integer value, this while loop starts in and saves the program from unexpected behavior.
        } else { // When a valid value is entered, this block is entered and the while loop is exited using the break statement.
            break;
        }
    }

    if (choice == 11) {
        printf("Program closed.\n");
        exit(0);
    }

    printf("How many random numbers should be generated and sorted?: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Random numbers between 0 and 100 will be generated
    }

    printf("\nUnsorted Array:\n");
    print_array(arr, n);

    switch (choice) {
        case 1:
            printf("\nThe Bubble Sort algorithm was chosen.\n");
            bubble_sort(arr, n);
            break;
            case 2:
                printf("\nThe Insertion Sort algorithm was chosen.\n");
                insertion_sort(arr, n);
                break;
            case 3:
                printf("\nThe Selection Sort algorithm was chosen.\n");
                selection_sort(arr, n);
                break;
            case 4:
                printf("\nThe Merge Sort algorithm was chosen.\n");
                merge_sort(arr, n);
                break;
            case 5:
                printf("\nThe Quick Sort algorithm was chosen.\n");
                quick_sort(arr, 0, n - 1);
                break;
            case 6:
                printf("\nThe Heap Sort algorithm was chosen.\n");
                heap_sort(arr, n);
                break;
            case 7:
                printf("\nThe Radix Sort algorithm was chosen.\n");
                radix_sort(arr, n);
                break;
            case 8:
                printf("\nThe Counting Sort algorithm was chosen.\n");
                counting_sort(arr, n, 101);
                break;
            case 9:
                printf("\nThe Bucket Sort algorithm was chosen.\n");
                bucket_sort(arr, n, 100);
                break;
            case 10:
                printf("\nThe Shell Sort algorithm was chosen.\n");
                shell_sort(arr, n);
                break;
    }

    printf("\nSorted Array:\n");
    print_array(arr, n);

    return 0;
}
