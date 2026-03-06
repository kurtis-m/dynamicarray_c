#include <stdio.h>
#include "array.h"

/*
 *for testing and debug purposes
 */
int main(void) {

    Array arr = createDynamicArray(4);

    printArray(&arr);

    for (int i = 0; i < 10; ++i) {
        addToArray(&arr,100 - i*5);
    }

    for (int i = 0; i < arr.size; ++i) {
        int value;
        arrayGet(&arr, i, &value);
        printf("%d\n",value);
    }

    freeArray(&arr);
    return 0;
}