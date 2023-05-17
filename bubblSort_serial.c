#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void bubble_sort_serial(int arr[], int n);

int main() {
    int i;
    int arr[MAX];

    // Generating Random Values...
    printf("Unsorted Data\n");
    srand(time(NULL));
    for (i = 0; i < MAX; i++) {
        arr[i] = rand() % MAX; 
        printf("%d ", arr[i]); 
    }

    printf("\n");

    clock_t t1, t2;
    t1 = clock();

    bubble_sort_serial(arr, MAX);

    t2 = clock();
    double t3 = (double)(t2 - t1) / CLOCKS_PER_SEC;
    
    printf("\nBubble Sorted Data\n");
    for (i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nBubble Sorted Time Elapsed: %.5f\n", t3);

    return 0;
}

void bubble_sort_serial(int arr[], int n) {
    int i,j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

