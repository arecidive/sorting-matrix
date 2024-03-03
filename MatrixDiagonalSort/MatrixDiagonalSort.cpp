#include <iostream>
#include <utility>

#include "DiagonalManipulator/DiagonalManipulator.h"
#include "SortingAlgorithmsMetrics/SortingAlgorithmsMetrics.h"

std::pair<int, int> bubbleSortDiagonals(int **matrix, int rows) {
    std::cout << "The matrix sorted by the bubble method:" << std::endl;
    return sortDiagonals(matrix, rows, bubbleSort);
}

std::pair<int, int> selectionSortDiagonals(int **matrix, int rows) {
    std::cout << "The matrix sorted by the selection method:" << std::endl;
    return sortDiagonals(matrix, rows, selectionSort);
}

std::pair<int, int> insertionSortDiagonals(int **matrix, int rows) {
    std::cout << "The matrix sorted by the insertion method:" << std::endl;
    return sortDiagonals(matrix, rows, insertionSort);
}

std::pair<int, int> shellSortDiagonals(int **matrix, int rows) {
    std::cout << "The matrix sorted by the shell method:" << std::endl;
    return sortDiagonals(matrix, rows, shellSort);
}

std::pair<int, int> quickSortDiagonals(int **matrix, int rows) {
    std::cout << "The matrix sorted by the quick method:" << std::endl;
    int *mainDiagonal = extractMainDiagonal(matrix, rows);

    SortStats stats = {0, 0};
    quickSort(mainDiagonal, rows, stats);

    for (int i = 0; i < rows; i++) {
        matrix[i][i] = mainDiagonal[i];
    }

    delete[] mainDiagonal;

    return std::make_pair(stats.comparisons, stats.swaps);
}