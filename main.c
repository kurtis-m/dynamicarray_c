#include <stdio.h>
#include <stdlib.h>

#include "array.h"

double getArrayAverage(const Array* arr) {
    if (arr->size == 0) return 0.0;

    long long sum = 0;
    for (size_t i = 0; i < arr->size; ++i) {
        int value;
        arrayGet(arr,i,&value);
        sum += value;
    }
    return (double) sum / arr->size;
}

/*
 *for testing and debug purposes
 */
int main(void) {

    Array arr = createDynamicArray(4);

    int input = 0;
    int count = 0;

    while (true) {
        printf("Enter in score %d:\n ",count+1);
        scanf("%d",&input);

        if (input < 0) break;
        addToArray(&arr,input);
        ++count;
    }

    printArray(&arr);
    selectionSort(&arr);
    printArray(&arr);

    printf("average: %f",getArrayAverage(&arr));

    freeArray(&arr);
    return 0;
}