#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int *A, int low, int high){
    // Pick as pivot the right most element
    int pivot = A[high];
    // Set index i as out of array so when we increment next
    // time (when we find first smaller than pivot element) will be our first
    int j,i=(low-1);
    //  Loop through the array as long as i < j
    for(j=low; j<=high-1; j++) {

        /* If the element is smaller or equal to the pivot,
         * then increment the i index and swap the elements
         * in first case we would swap with itself
         */
        if(A[j] <= pivot) {
            i++;
            swap(&A[j],&A[i]);
        }
    }
    // We reached high-1 so we swap automatically last element
    swap(&A[high],&A[i+1]);
    return (i+1);
}

void QuickSort(int A[], int low, int high) {
    int par;
    /* As long as low is lower than high element
     * Continue to partition the array and once we partitioned it
     * go on and Recursively partition again the left and the right one
     * until the pivot will be the only element and then we have a sorted array
     */
    if(low<high) { // If low=high then we have one element, so stop
        par = Partition(A,low,high); // Index of the pivot after partitioning the small
        // elements to left and bigger to right
        // Now we need to partition again the left and right one recursively

        QuickSort(A,low,par-1); // Left partition
        QuickSort(A,par+1, high);   // Right partition
    }
}

int main() {
    int A[] = {50,70,60,90,40,80,10,20,30};
    int n = sizeof(A) / sizeof(A[0]);
    QuickSort(A,0,n-1);

    for(int i=1;i<n;i++) {
        cout << A[i] << endl;
    }
    return 0;
}
