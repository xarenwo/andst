#include <iostream>
using namespace std;

//  Bubble sort

// Swap function
void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int A[], int n) {
    int flag; // Introduce flag to detect swaps and make it adaptive
    // We need to do n-1 passes
    // In every pass we have at the end n-i+1 sorted elements
    for(int i=0; i<n-1; i++) { // n-1 comparisons
        flag = 0;
        for(int j=0;j < n-i-1; j++) { // We are in n-1 pass and we compare A[j] with A[j+1]
                                        // n-i-1 because i grows every step, so we subtract each pass we go, the elements that are already sorted, so we don't count them again.
                                        // If A[j] is bigger, swap
            if(A[j] > A[j+ 1]) {  // O(n^2)
                Swap(&A[j],&A[j+1]); // It is an adaptive algorithm because if the list is ordered swap is never done.
                                    // If there are numbers that are the same they do not get swapped, and the second number will be swapped with lower numbers, thus means the
                                    //  algorithm does not interchange elements that are equal, and preserves their position, which makes it a stable algorithm
                flag = 1;
            }
        }
        if(flag==0) { // if list is sorted, we stop after 1st pass and we swap (0) , and comparisons are (n-1)
                        // time now is O(n) as minimum and max is O(n^2)
            break;
        }
    }
}

int main(){
    int A[] = {2,3,5,7,8};


    BubbleSort(A,5);


    for(int i=0; i<5; i++) {
        cout << A[i] << " ";
    }

}
