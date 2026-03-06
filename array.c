
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/**
 * Method that returns a pointer to a new dynamic array struct
 * @param initCapacity Initial capacity of the dynamic array
 * @return Pointer to the new dynamic array
 */
Array createDynamicArray(const size_t initCapacity) {
    Array arr;
    arr.data = (int*) malloc(initCapacity * sizeof(int));
    arr.size = 0;
    arr.capacity = initCapacity;
    return arr;
}

/**
 * Method that adds an integer value to a dynamic array
 * @param arr Array to be added to
 * @param value Value of the integer that is being added
 */
void addToArray(Array* arr, const int value) {
    if (arr->data == NULL) {
        fprintf(stderr, "Cannot add to NULL array data");
        return;
    }

    if (arr->size == arr->capacity) {
        const size_t nCapacity = arr->capacity * 2;
        int* nData = (int*) realloc(arr->data, nCapacity * sizeof(int));
        if (nData) {
            arr->data = nData;
            arr->capacity = nCapacity;
        }
        else {
            fprintf(stderr,"Realloc error\n");
            return;
        }
    }

    arr->data[arr->size] = value;
    ++arr->size;
}

/**
 * Removes and returns the last value in the array
 * @param arr Pointer to the array
 * @param result Pointer to store the result
 * @return True or false if the value was removed
 */
bool popFromArray(Array* arr, int* result) {
    if (arr->size == 0) return false;

    *result = arr->data[arr->size-1];
    --arr->size;
    return true;
}

/**
 * Get the value of the array at the desired index
 * @param arr Pointer to the array
 * @param index Index of the array
 * @param result Pointer to store the result
 * @return True or false if the get succeeded
 */
bool arrayGet(const Array* arr, const size_t index, int* result) {
    if (index >= arr->size) {
        fprintf(stderr, "Out of bounds index");
        return false;
    }
    *result = arr->data[index];
    return true;
}

/**
 * Method to print an array to the console
 * @param arr Pointer to the array to print
 */
void printArray(const Array* arr) {
    if (arr->size == 0) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (size_t i = 0; i < arr->size; ++i) {
        printf(i == 0 ? "%d" : ", %d",arr->data[i]);
    }
    printf("]\n");
}

/**
 * Method that frees the memory of the dynamic array's data
 * @param arr Pointer to the array to free
 */
void freeArray(Array* arr) {
    free(arr->data);
    arr->data = nullptr;
    arr->size = 0;
    arr->capacity = 0;
}

/**
 * Sorts a dynamic array in ascending order
 * @param arr Pointer to the array
 */
void selectionSort(Array* arr) {
    for (size_t i = 0; i < arr->size-1; ++i) {
        size_t current = i;

        for (size_t n = i + 1; n < arr->size; ++n) {
            if (arr->data[n] < arr->data[current]) {
                current = n;
            }
        }

        const int temp = arr->data[i];
        arr->data[i] = arr->data[current];
        arr->data[current] = temp;
    }
}
