//
// Created by lxx789 on 6/20/2024.
//
#include "merge_operations.h"

// Function to merge two sorted arrays and compute the overall average
void* mergeAndComputeOverallAverage(void* arg) {
    // Cast the argument to MergeData*
    MergeData* mergeData = (MergeData*)arg;

    // Get the two sorted arrays and their sizes
    double* array1 = mergeData->sortResult1.arrayData.array;
    int size1 = mergeData->sortResult1.arrayData.size;
    double* array2 = mergeData->sortResult2.arrayData.array;
    int size2 = mergeData->sortResult2.arrayData.size;

    // Allocate memory for the merged array
    double* mergedArray = malloc((size1 + size2) * sizeof(double));
    if (mergedArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Merge the two sorted arrays
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (array1[i] <= array2[j]) {
            mergedArray[k++] = array1[i++];
        } else {
            mergedArray[k++] = array2[j++];
        }
    }
    while (i < size1) {
        mergedArray[k++] = array1[i++];
    }
    while (j < size2) {
        mergedArray[k++] = array2[j++];
    }

    // Compute the overall average
    double overallAverage = (mergeData->sortResult1.average + mergeData->sortResult2.average) / 2;

    // Create a SortResult and set the merged array and the overall average
    SortResult* sortResult = malloc(sizeof(SortResult));
    if (sortResult == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    sortResult->arrayData.array = mergedArray;
    sortResult->arrayData.size = size1 + size2;
    sortResult->average = overallAverage;

    // Return the SortResult
    return sortResult;
}
