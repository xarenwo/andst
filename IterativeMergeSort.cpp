#include <iostream>
using namespace std;



void Merge(int A[], int low, int mid, int high) {
    int i,j,k;
    k=low;
    i=low;
    j=mid+1;
    int B[100];
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

void IMergeSort(int A[],int n)
{
    int p,l,h,mid,i;
    for(p=2;p<=n;p=p*2)
    {for(i=0;i+p-1<=n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n)
        Merge(A,0,p/2-1,n);
}

int main() {
    int A[] = {10, 20, 30, 40, 50, 42, 12};
    int sizeA = sizeof(A) / sizeof(A[0]);
    int middle = sizeA/2;
    cout << "Size of A is "<< sizeA << endl;
    IMergeSort(A,sizeA);
    for(int i=0; i<sizeA; i++) {
        cout << A[i] << endl;
    }
    return 0;
}
