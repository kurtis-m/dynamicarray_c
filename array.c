
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

#define DEFAULT_CAPACITY 8

/**
 * Method that returns a pointer to a new dynamic array struct
 * @return Pointer to the new dynamic array
 */
Array* initDynamicArray() {
    Array* arr = malloc(sizeof(Array));
    if (!arr) {
        fprintf(stderr,"Malloc error in array\n");
        return nullptr;
    }

    arr->data = (int*) malloc(DEFAULT_CAPACITY * sizeof(int));
    if (!arr->data) {
        fprintf(stderr,"Malloc error in array data\n");
        free(arr);
        return nullptr;
    }

    arr->size = 0;
    arr->capacity = DEFAULT_CAPACITY;
    return arr;
}

/**
 * Method that adds an integer value to a dynamic array
 * @param arr Array to be added to
 * @param value Value of the integer that is being added
 */
void addToArray(Array* arr, const int value) {
    if (!arr) {
        fprintf(stderr,"NULL array\n");
        return;
    }
    if (arr->data == nullptr) {
        fprintf(stderr, "Cannot add to NULL array data\n");
        return;
    }
    if (arr->size == arr->capacity) {
        const size_t nCapacity = arr->capacity * 2;
        int* nData = realloc(arr->data, nCapacity * sizeof(int));
        if (!nData) {
            fprintf(stderr,"Realloc error in array data\n");
            return;
        }
        arr->data = nData;
        arr->capacity = nCapacity;
    }

    arr->data[arr->size] = value;
    ++arr->size;
}

/**
 * Removes and returns the last value in the array
 * @param arr Pointer to the array
 * @param result Pointer to store the result
 */
bool popFromArray(Array* arr, int* result) {
    if (!arr) {
        fprintf(stderr,"NULL array\n");
        return false;
    }

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
 */
bool arrayGet(const Array* arr, const size_t index, int* result) {
    if (!arr) {
        fprintf(stderr,"NULL array\n");
        return false;
    }
    if (index >= arr->size) {
        fprintf(stderr, "Out of bounds index\n");
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
    if (!arr) {
        fprintf(stderr,"NULL array\n");
        return;
    }
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
    if (!arr) return;
    free(arr->data);
    arr->data = nullptr;
    arr->size = 0;
    arr->capacity = 0;
    free(arr);
}

/**
 * Trim the array capacity to the minimum size
 * @param arr Pointer to the array
 */
void trimArray(Array* arr) {
    if (!arr) {
        fprintf(stderr,"NULL array\n");
        return;
    }

    const size_t nCapacity = arr->size <= DEFAULT_CAPACITY ? DEFAULT_CAPACITY : arr->size;
    int* nData = realloc(arr->data,nCapacity * sizeof(int));
    if (!nData) {
        fprintf(stderr,"Realloc error\n");
        return;
    }
    arr->data = nData;
    arr->capacity = nCapacity;
}

/**
 * Sorts a dynamic array in ascending order
 * @param arr Pointer to the array
 */
void selectionSort(Array* arr) {
    if (!arr) {
        fprintf(stderr,"NULL array\n");
        return;
    }

    if (arr->size <= 1) return;

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
