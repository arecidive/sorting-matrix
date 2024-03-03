#include <iostream>
#include <utility>

int *extractMainDiagonal(int **matrix, int rows) {
    int *mainDiagonal = new int[rows];
    for (int i = 0; i < rows; i++) {
        mainDiagonal[i] = matrix[i][i];
    }

    return mainDiagonal;
}

std::pair<int, int> sortDiagonals(int **matrix, int rows, std::pair<int, int> (*sortFunc)(int *, int)) {
    int *mainDiagonal = extractMainDiagonal(matrix, rows);

    std::pair<int, int> mainCounts = sortFunc(mainDiagonal, rows);
    for (int i = 0; i < rows; i++) {
        matrix[i][i] = mainDiagonal[i];
    }

    delete[] mainDiagonal;

    return mainCounts;
}