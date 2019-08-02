#include <iostream>

using namespace std;


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void selectionSort(int A[], int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++) {
        // Iterate through array in n-1 passes, once we find a small element for each pass, we swap that element for the current A[i] element.
        // That way we always find smallest A[j] = A[k] and we go on through the array until we reach the last smallest and we have our array in order.
        // Each time we go through a pass, we sort one element
        // Find smallest element in each pass
        for(j=k=i; j<n; j++) {
            if(A[j] < A[k]) { // We are looking for an element that is smaller than the smallest.
                cout << "A[j] is " << A[j] << " and A[k] is "<< A[k] << " ||| A[j] < A[k] " << (A[j]<A[k]) << endl;
                k = j; // Point k to smallest element j
            }
        }
        // Swap smallest element with the current element in the array A[i]
        swap(&A[k],&A[i]); // Using selection sort we have n-1 swaps, the only algorithm with minimum amount of swaps, so it uses less memory.
        // If i perform K passes, i get K smaller elements, which means i sort K elements.
        // This is not an adaptive algorithm as we can't know if the list is sorted of not in the beginning.
        // It is also not a stable algorithm as if there is a smallest number after second duplicate, we will interchange the elements and lose the order of duplicates.
    }
}

int main () {
    int A[] = {8,6,3,2,5,4}; // n = 6

    selectionSort(A,6);
    printArray(A,6);
    return 0;
}
