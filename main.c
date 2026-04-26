#include <stdio.h>
#include <stdlib.h>

#include "array.h"


/*
 *for testing and debug purposes
 */
int main(void) {

    Array* arr = initDynamicArray();

    int input = 0;
    int count = 0;

    while (true) {
        printf("Enter in score %d:\n ",count+1);
        scanf("%d",&input);

        if (input < 0) break;
        addToArray(arr,input);
        ++count;
    }

    printArray(arr);
    selectionSort(arr);
    printArray(arr);


    freeArray(arr);
    return 0;
}