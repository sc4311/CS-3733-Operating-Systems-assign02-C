#include <pthread.h>
#include "array_operations.h"
#include "merge_operations.h"


int main(int argc, char* argv[]) {
    // Parse the command line argument
    int n = atoi(argv[1]);

    // Generate the array of random values
    double* A = generateRandomValues(n);

    // Create the array for the one-thread case
    double* B = copyArray(A, n);

    // Measure the time for the one-thread case
    struct timespec ts_begin, ts_end;
    clock_gettime(CLOCK_MONOTONIC, &ts_begin);

    // Create the sorting thread
    pthread_t thB;
    ArrayData arrayDataB = {B, n};
    pthread_create(&thB, NULL, sortAndComputeAverage, &arrayDataB);

    // Wait for the sorting thread to finish
    pthread_join(thB, NULL);

    // Measure the elapsed time
    clock_gettime(CLOCK_MONOTONIC, &ts_end);
    double elapsed = (ts_end.tv_sec - ts_begin.tv_sec) + (ts_end.tv_nsec - ts_begin.tv_nsec) / 1000000000.0;

    // Print the result
    printf("Sorting by ONE thread is done in %f ms\n", elapsed * 1000);

    // Create the arrays for the two-thread case
    double* aFirstHalf = copyArray(A, n / 2);
    double* aSecondHalf = copyArray(A + n / 2, n / 2);

    // Measure the time for the two-thread case
    clock_gettime(CLOCK_MONOTONIC, &ts_begin);

    // Create the sorting threads
    pthread_t thA1, thA2;
    ArrayData arrayDataA1 = {aFirstHalf, n / 2};
    ArrayData arrayDataA2 = {aSecondHalf, n / 2};
    pthread_create(&thA1, NULL, sortAndComputeAverage, &arrayDataA1);
    pthread_create(&thA2, NULL, sortAndComputeAverage, &arrayDataA2);

    // Wait for the sorting threads to finish
    pthread_join(thA1, NULL);
    pthread_join(thA2, NULL);

    // Create the merging thread
    pthread_t thM;
    SortResult* sortResultA1 = sortAndComputeAverage(&arrayDataA1);
    SortResult* sortResultA2 = sortAndComputeAverage(&arrayDataA2);
    MergeData mergeData = {*sortResultA1, *sortResultA2};
    pthread_create(&thM, NULL, mergeAndComputeOverallAverage, &mergeData);

    // Wait for the merging thread to finish
    pthread_join(thM, NULL);

    // Measure the elapsed time
    clock_gettime(CLOCK_MONOTONIC, &ts_end);
    elapsed = (ts_end.tv_sec - ts_begin.tv_sec) + (ts_end.tv_nsec - ts_begin.tv_nsec) / 1000000000.0;

    // Print the result
    printf("Sorting by TWO threads is done in %f ms\n", elapsed * 1000);

    return 0;
}