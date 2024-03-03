#include <iostream>
#include <utility>

#include "SortingAlgorithmsMetrics.h"

std::pair<int, int> bubbleSort(int *arr, int size) {
    int temp_value;

    int comparisons = 0, swaps = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                temp_value = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp_value;
                swaps++;
            }
        }
    }

    return std::make_pair(comparisons, swaps);
}

std::pair<int, int> selectionSort(int *arr, int size) {
    int min_value, temp_value;

    int comparisons = 0, swaps = 0;
    for (int i = 0; i < size - 1; i++) {

        min_value = i;
        for (int j = i + 1; j < size; j++) {
            comparisons++;
            if (arr[j] < arr[min_value]) {
                min_value = j;
            }
        }

        if (min_value == i) {
            continue;
        }

        temp_value = arr[i];
        arr[i] = arr[min_value];
        arr[min_value] = temp_value;
        swaps++;
    }

    return std::make_pair(comparisons, swaps);
}

std::pair<int, int> insertionSort(int *arr, int size) {
    int comparisons = 0, swaps = 0;

    int current_value, temp_value;
    for (int i = 1; i < size; i++) {
        current_value = arr[i];

        int j = i - 1;
        if (arr[j] <= current_value) {
            comparisons++;
        }

        while (j >= 0 && arr[j] > current_value) {
            comparisons++;
            temp_value = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp_value;
            swaps++;
            j--;
        }
    }

    return std::make_pair(comparisons, swaps);
}

std::pair<int, int> shellSort(int *arr, int size) {
    int comparisons = 0, swaps = 0;
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i += 1) {

            int j, temp = arr[i];
            if (arr[i - interval] <= temp) {
                comparisons++;
            }

            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                comparisons++;
                arr[j] = arr[j - interval];
                swaps++;
            }

            arr[j] = temp;
        }
    }

    return std::make_pair(comparisons, swaps);
}

void quickSort(int *arr, int size, SortStats &stats) {
    int i = 0;
    int j = size - 1;
    int mid = arr[size / 2];

    do {
        while (arr[i] < mid) {
            i++;
            stats.comparisons++;
        }

        if (arr[i] >= mid) {
            stats.comparisons++;
        }

        while (arr[j] > mid) {
            j--;
            stats.comparisons++;
        }

        if (arr[j] <= mid) {
            stats.comparisons++;
        }

        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            stats.swaps++;

            i++;
            j--;
        }

    } while (i <= j);


    if (j > 0) {
        quickSort(arr, j + 1, stats);
    }

    if (i < size) {
        quickSort(&arr[i], size - i, stats);
    }
}