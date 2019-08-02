#include <stdio.h>
#include <stdlib.h>


typedef struct MaxHeap {
    int size;
    int* array;
} MaxHeap ;


void swap(int* a,int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}


void maxHeapify(MaxHeap * maxheap, int n) {
    int largest = n;
    int left = (2*n) + 1;
    int right = (2*n) + 2;
    if (left < maxheap->size && maxheap->array[left] > maxheap->array[largest]) {
        largest = left;
    }

    if (right < maxheap->size && maxheap->array[right] > maxheap->array[largest]) {
        largest = right;
    }


    if(largest != n) {
        swap(&maxheap->array[largest], &maxheap->array[n]);
        maxHeapify(maxheap, largest);
    }

}

MaxHeap * createAndBuild(int *array, int size)
{
    int i;
    MaxHeap *maxHeap = (MaxHeap*) malloc(sizeof(maxHeap));
    maxHeap->size = size;
    maxHeap->array = array;

    for(i = (maxHeap->size - 2) / 2; i>=0; --i) {
        maxHeapify(maxHeap,i);
    }
    return maxHeap;

}

void heapSort(int* array, int size)
{
    MaxHeap* maxHeap = createAndBuild(array,size);

    while(maxHeap->size > 1)
    {
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --maxHeap->size;


        maxHeapify(maxHeap,0);
    }
}

void printSorted(int *array, int size) {
    int i;
    for(i=0; i<size;++i){
        printf("%d ",array[i]);
    }
}


int main() {
    int array[] = {10,20,30,25,5,40,35,50,39,90,99,12,1,3,6,0,392};
    int size = sizeof(array)/sizeof(array[0]);

    heapSort(array,size);

    printf("\nSorted : \n");
    printSorted(array,size);
}
