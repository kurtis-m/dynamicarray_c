#include <stdio.h>
#include <stdlib.h>

/**
 * Struct representing a dymanic array of integers
 */
typedef struct Array {
    int* data;
    size_t size;
    size_t capacity;
} Array;

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
        arr->data = (int*) realloc(arr->data, arr->capacity * 2 * sizeof(int));
        if (arr->data == NULL) {
            fprintf(stderr, "Realloc error");
            return;
        }
        arr->capacity *= 2;
    }

    arr->data[arr->size] = value;
    ++arr->size;
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
        printf("%d",arr->data[i]);
        if (i != arr->size-1) printf(", ");
    }
    printf("]\n");
}

/**
 * Method that frees the memory of the dynamic array's data
 * @param arr Pointer to the array to free
 */
void freeArray(Array* arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

/*
 *for testing and debug purposes
 */
int main(void) {

    Array arr = createDynamicArray(4);

    for (int i = 0; i < 10; ++i) {
        addToArray(&arr, 5 * i);
        printArray(&arr);
    }

    printArray(&arr);

    freeArray(&arr);
    return 0;
}