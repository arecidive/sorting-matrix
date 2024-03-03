#include <iomanip>
#include <iostream>

int **copyMatrix(int **matrix, int rows, int cols) {
    int **copiedMatrix = new int *[rows];
    for (int i = 0; i < rows; i++) {
        copiedMatrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            copiedMatrix[i][j] = matrix[i][j];
        }
    }
    return copiedMatrix;
}

void deleteMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(4) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}