#ifndef LAB6_MATRIX_DIAGONALMANIPULATOR_H
#define LAB6_MATRIX_DIAGONALMANIPULATOR_H

std::pair<int, int> sortDiagonals(int **matrix, int rows, std::pair<int, int> (*sortFunc)(int*, int));
int *extractMainDiagonal(int **matrix, int rows);

#endif