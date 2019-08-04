#include <iostream>
using namespace std;


void Merge(int A[], int low, int mid, int high) {
    int i,j,k;
    k=low;
    i=low;
    j=mid+1;
    int B[high+10];
    while(i<=mid && j<=high)
    {
        if(A[i]<A[j]) {
            B[k] = A[i++];
            k++;
        }
        else {
            B[k] = A[j++];
            k++;
        }
    }
    for(;i<=mid;i++) {
        B[k]=A[i];
        k++;
    }
    for(;j<=high;j++) {
        B[k]=A[j];
        k++;
    }
    for(int x = low; x<=high; x++) {
        A[x] = B[x];
    }

}

void MergeSort(int A[],int low, int high) {
    int mid;
    if(low<high) {
        mid = (low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}


int main() {
    int A[] = {10, 20, 30, 40, 50, 42, 12};
    int sizeA = sizeof(A) / sizeof(A[0]);
    int middle = sizeA/2;
    cout << "Size of A is "<< sizeA << endl;
    MergeSort(A,0,sizeA-1);
    for(int i=0; i<sizeA; i++) {
        cout << A[i] << endl;
    }
    return 0;
}
