#include <stdio.h>
#include <omp.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place
        #pragma omp parallel for num_threads(2) shared(arr)
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX], i;
    srand(time(NULL));
    for (i = 0; i < MAX; i++) {
        arr[i] = rand() % MAX;
    }
    printf("Unsorted array: ");
    for (i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    clock_t t1, t2;
    t1 = clock();
    bubbleSort(arr, MAX);
    t2 = clock();
    printf("Sorted array: ");
    for (i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    double t_time = (double)(t2-t1)/CLOCKS_PER_SEC;
    printf("\t\tTime Elapsed: %.5f\n", t_time);
    return 0;
}

