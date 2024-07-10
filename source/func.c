#include "func.h"

void Arr_print(int *arr, int length)
{
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}