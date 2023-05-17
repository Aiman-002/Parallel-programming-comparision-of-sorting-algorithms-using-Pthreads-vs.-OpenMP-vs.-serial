#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<time.h>

#define MAX 1000

void *bubble_sort_pthread(void *);
int arr[MAX];

struct ArrayIndex {
    int start;
    int end;
};

int main() {
	int i;
    struct ArrayIndex ai;
    ai.start = 0;
    ai.end = MAX - 1;

    pthread_t t;
    int retval;

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

    retval = pthread_create(&t, NULL, bubble_sort_pthread, &ai);
    if (retval) {  
        printf("Thread Creation Failed...!! Return value is %d\n", retval);
        return 0;
    }

    pthread_join(t, NULL);
    t2 = clock();
    double t3 = (double)(t2 - t1) / CLOCKS_PER_SEC;
    
    printf("\nBubble Sorted Data\n");
    for (i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nBubble Sorted Time Elapsed by thread: %.5f\n", t3);

    return 0;
}

void *bubble_sort_pthread(void *ptr) {
    struct ArrayIndex *p = (struct ArrayIndex *)ptr;
    int i,j;
    for (i = p->start; i < p->end; i++) {
        for (j = p->start; j < p->end - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return 0;
}

