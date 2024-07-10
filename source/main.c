#include <stdio.h>
#include "sort.h"
int main() {
    int a[4]= {5,564,21,78};
    Quick_sort(a,0,3);
    Arr_print(a,4);
}