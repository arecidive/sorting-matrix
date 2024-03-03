#include <iostream>
#include <windows.h>
#include <utility>
#include <ctime>

#include "ParamInputValidator/ParamInputValidator.h"
#include "MatrixUtils/MatrixUtils.h"
#include "MatrixDiagonalSort/MatrixDiagonalSort.h"

void setConsoleBufferSize(int width) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    consoleInfo.dwSize.X = width;
    SetConsoleScreenBufferSize(hConsole, consoleInfo.dwSize);
}

std::pair<int, int> sortAndPrint(int **matrix, int rows, int cols, std::pair<int, int> (*sortFunc)(int **, int)) {
    int diag, **sortedMatrix = copyMatrix(matrix, rows, cols);
    rows < cols ? diag = rows : diag = cols;
    std::pair<int, int> counts = sortFunc(sortedMatrix, diag);
    printMatrix(sortedMatrix, rows, cols);
    deleteMatrix(sortedMatrix, rows);
    std::cout << "\n";
    return counts;
}

int main() {
    srand(time(0));
    setConsoleBufferSize(1000);

    int rows = getPositiveNumber("N");
    int cols = getPositiveNumber("M");
    std::cout << "\n";

    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 1;
        }
    }

    std::cout << "The original matrix:" << std::endl;
    printMatrix(matrix, rows, cols);
    std::cout << "\n";

    std::pair<int, int> bubbleCounts = sortAndPrint(matrix, rows, cols, bubbleSortDiagonals);
    std::pair<int, int> selectionCounts = sortAndPrint(matrix, rows, cols, selectionSortDiagonals);
    std::pair<int, int> insertionCounts = sortAndPrint(matrix, rows, cols, insertionSortDiagonals);
    std::pair<int, int> shellCounts = sortAndPrint(matrix, rows, cols, shellSortDiagonals);
    std::pair<int, int> quickCounts = sortAndPrint(matrix, rows, cols, quickSortDiagonals);

    std::cout << "Method\t\tComparisons\tSwaps\n";

    std::cout << "Bubble Sort\t" << bubbleCounts.first << "\t\t" << bubbleCounts.second << "\n";
    std::cout << "Selection Sort\t" << selectionCounts.first << "\t\t" << selectionCounts.second << "\n";
    std::cout << "Insertion Sort\t" << insertionCounts.first << "\t\t" << insertionCounts.second << "\n";
    std::cout << "Shell Sort\t" << shellCounts.first << "\t\t" << shellCounts.second << "\n";
    std::cout << "Quick Sort\t" << quickCounts.first << "\t\t" << quickCounts.second << "\n";

    deleteMatrix(matrix, rows);

    return 0;
}