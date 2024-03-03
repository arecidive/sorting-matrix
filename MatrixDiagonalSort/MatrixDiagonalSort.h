#ifndef LAB6_MATRIX_MATRIXDIAGONALSORT_H
#define LAB6_MATRIX_MATRIXDIAGONALSORT_H

std::pair<int, int> bubbleSortDiagonals(int **matrix, int rows);
std::pair<int, int> selectionSortDiagonals(int **matrix, int rows);
std::pair<int, int> insertionSortDiagonals(int **matrix, int rows);
std::pair<int, int> shellSortDiagonals(int **matrix, int rows);
std::pair<int, int> quickSortDiagonals(int **matrix, int rows);

#endif