#pragma once
#include <stdio.h>

#ifndef DYNAMICARRAY_C_ARRAY_H
#define DYNAMICARRAY_C_ARRAY_H

/**
 * Struct representing a dynamic array of integers
 */
typedef struct Array {
    int* data;
    size_t size;
    size_t capacity;
} Array;

Array createDynamicArray(size_t initCapacity);
void addToArray(Array* arr, int value);
bool popFromArray(Array* arr, int* result);
bool arrayGet(const Array* arr, size_t index, int* result);
void printArray(const Array* arr);
void freeArray(Array* arr);
void selectionSort(Array* arr);


#endif //DYNAMICARRAY_C_ARRAY_H