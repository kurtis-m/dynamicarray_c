
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

#define DEFAULT_CAPACITY 8

struct dynamic_array {
    int* data;
    size_t size;
    size_t capacity;
};

Array* initDynamicArray() {
    Array* arr = malloc(sizeof(Array));
    if (!arr) return nullptr;
    arr->data = (int*) malloc(DEFAULT_CAPACITY * sizeof(int));
    if (!arr->data) {
        free(arr);
        return nullptr;
    }
    arr->size = 0;
    arr->capacity = DEFAULT_CAPACITY;
    return arr;
}

void addToArray(Array* arr, const int value) {
    if (!arr) return;
    if (arr->data == nullptr) return;

    if (arr->size == arr->capacity) {
        const size_t nCapacity = arr->capacity * 2;
        int* nData = realloc(arr->data, nCapacity * sizeof(int));
        if (!nData) return;

        arr->data = nData;
        arr->capacity = nCapacity;
    }

    arr->data[arr->size] = value;
    ++arr->size;
}

bool popFromArray(Array* arr, int* result) {
    if (!arr) return false;
    if (arr->size == 0) return false;

    *result = arr->data[arr->size-1];
    --arr->size;
    return true;
}

bool arrayGet(const Array* arr, const size_t index, int* result) {
    if (!arr) return false;
    if (index >= arr->size) return false;

    *result = arr->data[index];
    return true;
}

void printArray(const Array* arr) {
    if (!arr) return;
    if (arr->size == 0) {
        printf("[]\n");
        return;
    }
    printf("[");
    for (size_t i = 0; i < arr->size; ++i) {
        printf(i == 0 ? "%d" : ", %d",arr->data[i]);
    }
    printf("]\n");
    printf("Size: %lu\nCapacity: %lu\n\n", arr->size, arr->capacity);

}

void freeArray(Array* arr) {
    if (!arr) return;
    free(arr->data);
    arr->data = nullptr;
    arr->size = arr->capacity = 0;
    free(arr);
}

void trimArray(Array* arr) {
    if (!arr) return;

    const size_t nCapacity = arr->size <= DEFAULT_CAPACITY ? DEFAULT_CAPACITY : arr->size;
    int* nData = realloc(arr->data,nCapacity * sizeof(int));
    if (!nData) return;

    arr->data = nData;
    arr->capacity = nCapacity;
}

void selectionSort(Array* arr) {
    if (!arr) return;
    if (arr->size <= 1) return;

    for (size_t i = 0; i < arr->size-1; ++i) {
        size_t current = i;
        for (size_t n = i + 1; n < arr->size; ++n) {
            if (arr->data[n] < arr->data[current]) current = n;
        }
        const int temp = arr->data[i];
        arr->data[i] = arr->data[current];
        arr->data[current] = temp;
    }
}
