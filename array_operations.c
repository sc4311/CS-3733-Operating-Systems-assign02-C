//
// Created by lxx789 on 6/20/2024.
//
#include "array_operations.h"
#include <time.h>
// Function to generate random double values double*
double* generateRandomValues(int size) {
    // Allocate memory for the array
    double* array = malloc(size * sizeof(double));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Seed the random number generator
    srand(time(NULL));

    // Fill the array with random double values between 1.0 and 1000.0
    for (int i = 0; i < size; i++) {
        array[i] = 1.0 + (double)rand() / RAND_MAX * (1000.0 - 1.0);
    }

    return array;
}


// Function to copy an array
double* copyArray(double* array, int size) {
    // Allocate memory for the new array
    double* newArray = malloc(size * sizeof(double));
    if (newArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Copy the elements from the given array to the new array
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }

    return newArray;
}


// Function to sort an array and compute its average
void* sortAndComputeAverage(void* arg) {
    // Cast the argument to ArrayData*
    ArrayData* arrayData = (ArrayData*)arg;

    // Get the array and its size
    double* array = arrayData->array;
    int size = arrayData->size;

    // Sort the array using insertion sort
    for (int i = 1; i < size; i++) {
        double key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }

    // Compute the average
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    double average = sum / size;

    // Create a SortResult and set the sorted array and the average
    SortResult* sortResult = malloc(sizeof(SortResult));
    if (sortResult == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    sortResult->arrayData.array = array;
    sortResult->arrayData.size = size;
    sortResult->average = average;

    // Return the SortResult
    return sortResult;
}