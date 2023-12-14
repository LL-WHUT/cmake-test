#include "sort.h"

void Arr_print(int arr[], int length)
{
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Random_arr(int arr[], int length)
{
    for (int i = 0; i < length; i++) {
        srand((unsigned)time(NULL) + (unsigned)rand());
        arr[i] = rand() % LENGTH;
    }
}

void Selection_sort(int arr[], int length) // O(n^2) O(1)
{
    int i, j, temp;
    for (i = 0; i < length; i++) {
        for (j = i; j < length; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Bubble_sort(int arr[], int length) // O(n^2) O(1)
{
    int i, j, temp;
    for (i = 1; i < length; i++) {
        for (j = 0; j < length - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Insert_sort(int arr[], int length) // O(n^2) O(1)
{
    int i, j, temp;
    for (i = 1; i < length; i++) {
        if (arr[i] < arr[i - 1]) {
            j = i - 1;
            temp = arr[i];
            while (j >= 0 && temp < arr[j]) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }
}

void Shell_sort(int arr[], int length) // O(n log n) O(1)
{
    int i, j, k, temp, gap;
    for (gap = length / 2; gap > 0; gap /= 2) {
        for (i = 0; i < gap; i++) // i是每次分组的第一个元素下标
        {
            for (j = i + gap; j < length; j += gap) {
                temp = arr[j];
                k = j - gap;
                while (k >= 0 && arr[k] > temp) {
                    arr[k + gap] = arr[k];
                    k -= gap;
                }
                arr[k + gap] = temp;
            }
        }
    }
}

void Quick_sort(int arr[], int left, int right) // O(n log n) O(n log n)
{
    if (left >= right) {
        return;
    }

    int i = left;
    int j = right;
    int key = arr[i];

    // 一轮
    while (i < j) {
        while (i < j && arr[j] >= key) {
            j--;
        }
        arr[i] = arr[j];

        while (i < j && arr[i] <= key) {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = key;

    Quick_sort(arr, left, i - 1);  // 左边
    Quick_sort(arr, i + 1, right); // 右边
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1; // 左半部分的大小
    int n2 = right - mid;    // 右半部分大小

    // 创建两个临时数组来存储两个子数组
    int L[n1], R[n2];

    // 将数据复制到临时数组L[[和R[]中
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;    // 初始化左半部分索引
    j = 0;    // 初始化右半部分索引
    k = left; // 初始化归并后数组索引

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制L[] 和 R[]的剩余元素(如果有)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Merge_sort(int arr[], int left, int right) // O(n log n) O(n)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        Merge_sort(arr, left, mid);      // 递归排序左半部分
        Merge_sort(arr, mid + 1, right); // 递归排序右半部分
        merge(arr, left, mid, right);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) // n为数组长度，i为树的根
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // 左子结点大
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // 右子结点大
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是当前结点，交换它们并递归调整堆
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void Heap_sort(int arr[], int n) // O(n log n) O(1)
{

    // 初始化最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        // 将堆顶元素与当前未排序部分的最后一个元素交换
        swap(&arr[0], &arr[i]);
        // 重新调整堆，确保剩余部分仍然是最大堆
        heapify(arr, i, 0);
    }
}

void Count_sort(int arr[], int length) // O(n + k) O(k)
{
    int max = arr[0], min = arr[0];

    // 求出数组的最大值和最小值
    for (int i = 0; i < length; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int *temp = (int *)calloc(range, sizeof(int));

    // 开始计数
    for (int i = 0; i < length; i++) {
        temp[arr[i] - min] += 1;
    }

    // 根据统计结果，重新对元素进行回收
    int j = 0;
    for (int i = 0; i < range; i++) {
        while (temp[i]--) {
            arr[j++] = i + min;
        }
    }

    // 释放临时数组
    free(temp);
    temp = NULL;
}