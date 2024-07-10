#ifndef _SORT_H_
#define _SORT_H_

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define LENGTH 100
void Arr_print(int arr[], int length);

void Random_arr(int arr[], int length);

void Selection_sort(int arr[], int length);

void Bubble_sort(int arr[], int length);

void Insert_sort(int arr[], int length);

void Shell_sort(int arr[], int length);

void Quick_sort(int arr[], int left, int right);

void merge(int arr[], int left, int mid, int right);
void Merge_sort(int arr[], int left, int right);

void swap(int *a, int *b);
void heapify(int arr[], int n, int i);
void Heap_sort(int arr[], int n);

void Count_sort(int arr[], int length);

#endif // _SORT_H_