//
// Created by lxx789 on 6/20/2024.
//

#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

#include <stdlib.h>
#include <stdio.h>

// Define a struct to hold the array and its size
typedef struct {
    double* array;
    int size;
} ArrayData;

// Define a struct to hold the array data and the average
typedef struct {
    ArrayData arrayData;
    double average;
} SortResult;

double* generateRandomValues(int size);
double* copyArray(double* array, int size);
void* sortAndComputeAverage(void* arg);

#endif