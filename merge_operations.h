//
// Created by 006li on 6/20/2024.
//

#ifndef MERGE_OPERATIONS_H
#define MERGE_OPERATIONS_H

#include "array_operations.h"


// Define a struct to hold the two sorted arrays and their averages
typedef struct {
    SortResult sortResult1;
    SortResult sortResult2;
} MergeData;

void* mergeAndComputeOverallAverage(void* arg);

#endif
