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

/**
 * Initializes a dynamic array
 * @return Pointer to the new dynamic array
 */
Array* initDynamicArray();

/**
 * Adds an integer to the dynamic array
 * @param arr Pointer to the array
 * @param value Integer value to be added
 */
void addToArray(Array* arr, int value);

/**
 * Removes and returns the last integer in the dynamic array
 * @param arr Pointer to the array
 * @param result Pointer to the result
 * @return True or false if the integer was popped
 */
bool popFromArray(Array* arr, int* result);

/**
 * Returns an integer at the desired index from a dynamic array
 * @param arr Pointer to the array
 * @param index Index of the array
 * @param result Pointer to the result
 * @return True or false if the integer was successfully retrieved
 */
bool arrayGet(const Array* arr, size_t index, int* result);

/**
 * Prints the desired dynamic array to the console
 * @param arr Pointer to the array
 */
void printArray(const Array* arr);

/**
 * Frees the dynamic array
 * @param arr Pointer to the array
 */
void freeArray(Array* arr);

/**
 * Trims the capacity of the dynamic array to the current size
 * @param arr Pointer to the array
 */
void trimArray(Array* arr);

/**
 * Uses the selection sort algorithm to sort a dynamic array
 * @param arr Pointer to an array
 */
void selectionSort(Array* arr);


#endif //DYNAMICARRAY_C_ARRAY_H