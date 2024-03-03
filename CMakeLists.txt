cmake_minimum_required(VERSION 3.27)
project(lab6_matrix)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab6_matrix main.cpp
        ParamInputValidator/ParamInputValidator.cpp
        ParamInputValidator/ParamInputValidator.h
        MatrixUtils/MatrixUtils.cpp
        MatrixUtils/MatrixUtils.h
        MatrixDiagonalSort/MatrixDiagonalSort.cpp
        MatrixDiagonalSort/MatrixDiagonalSort.h
        MatrixDiagonalSort/DiagonalManipulator/DiagonalManipulator.cpp
        MatrixDiagonalSort/DiagonalManipulator/DiagonalManipulator.h
        MatrixDiagonalSort/SortingAlgorithmsMetrics/SortingAlgorithmsMetrics.cpp
        MatrixDiagonalSort/SortingAlgorithmsMetrics/SortingAlgorithmsMetrics.h)
