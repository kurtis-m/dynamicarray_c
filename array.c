
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

#define DEFAULT_CAPACITY 8

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

void freeArray(Array* arr) {
    if (!arr) return;
    free(arr->data);
    arr->data = nullptr;
    arr->size = 0;
    arr->capacity = 0;
    free(arr);
}

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
