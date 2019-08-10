#include <iostream>
void * Merge(int A[], int low, int mid, int high) {
    int i,j,k;
    int m = mid-low+1;
    int n = high-mid;
    int Left[m], Right[n];

    // Let's copy the data to two separate arrays so then we can compare them and merge back into original array.
    for(i=0;i<m;i++) {
        // Put in the array the elements until mid (mid included)
        Left[i] = A[low+i];
    }
    for(j=0;j<n;j++) {
        // Put in the right array the elements after mid
        Right[j] = A[mid + 1 + j];
    }

    i=0;
    j=0;
    k=low; // K is the index of original array A, reset it to the lowest index
    while(i<m && j<n) { // While there are elements in both of the arrays
        if(Left[i] <= Right[j]) { // If the left element is smaller, copy it to the original array and increment indexes
            A[k++] = Left[i++];
        }
        else
        {
            // Copy the right element and increment indexes
            A[k++] = Right[j++];
        }
    }

    // Now we are continuing from the last m,n in case there are elements left in any of the 2 arrays.
    for(;i<m;i++){
        A[k++] = Left[i];
    }
    for(;j<n;j++){
        A[k++] = Right[j];
    }
}

void * MergeSort(int A[], int low, int high) {
    int mid;
    if(low<high) {
        mid = (low+high)/2; // break the problem (divide and conquer)
        std::cout << "\n Mid is now " << mid << "\n";
        std::cout << "\n Making left array starting at " << low << " up to " << mid << "\n";
        MergeSort(A,low,mid); // take care of left problem
        std::cout << "\n Making right array starting at " << mid+1 << " up to " << high << "\n";
        MergeSort(A,mid+1,high); // take care of right problem
        std::cout << "\n Merging elements ... \n";
        Merge(A,low,mid,high);
    }
}
int main() {
    int A[] = {6,42,124,5,61,24,5,40};
    int arr_size = sizeof(A)/sizeof(A[0]);
    std::cout  << "Size is : " << arr_size << "\n";
    MergeSort(A,0,arr_size-1);
    for(int i=0;i<arr_size;i++) {
        std::cout << A[i] << "\n";
    }
    return 0;
}
