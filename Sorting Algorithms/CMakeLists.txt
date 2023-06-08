cmake_minimum_required(VERSION 3.25)
project(Sorting_Algorithms C)

set(CMAKE_C_STANDARD 23)

add_executable(Sorting_Algorithms main.c bubble_sort.h bubble_sort.c insertion_sort.h insertion_sort.c selection_sort.h selection_sort.c merge_sort.h merge_sort.c quick_sort.h quick_sort.c heap_sort.h heap_sort.c radix_sort.c radix_sort.h counting_sort.h counting_sort.c bucket_sort.h bucket_sort.c shell_sort.h shell_sort.c)
