#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

int partition(int arr[], int low, int high) {
    int pivot = arr[high], temp;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX];
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand() % MAX;
    }

    clock_t t1, t2;
    t1 = clock();
    quickSort(arr, 0, MAX - 1);
    t2 = clock();
    double t_time = (double)(t2 - t1) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    printArray(arr, MAX);
    printf("\t\tTime Elapsed: %.5f\n", t_time);

    return 0;
}

