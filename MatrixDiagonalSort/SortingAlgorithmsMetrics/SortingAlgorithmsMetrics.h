#ifndef LAB6_MATRIX_SORTINGALGORITHMSMETRICS_H
#define LAB6_MATRIX_SORTINGALGORITHMSMETRICS_H

struct SortStats {
    int comparisons;
    int swaps;
};

std::pair<int, int> bubbleSort(int *arr, int size);
std::pair<int, int> selectionSort(int *arr, int size);
std::pair<int, int> insertionSort(int *arr, int size);
std::pair<int, int> shellSort(int *arr, int size);
void quickSort(int *arr, int size, SortStats &stats);

#endif