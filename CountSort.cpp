#include <iostream>


using namespace std;

int findMax(int A[],int ssize) {
    int maxN=-1;
    for(int i=0; i<ssize; i++) {
        if(A[i] > maxN) {
            maxN = A[i];
        }
    }
    return maxN;
}

void countSort(int A[], int mmax,int ssize) {
    int *arr;
    arr=new int[mmax+1];
    for(int i=0;i<=mmax;i++) {
        arr[i] = 0;
    }
    for(int i=1;i<=ssize;i++) {
        arr[A[i]]++;
    }

    int i=0;
    int j=0;
    while(i<mmax+1) {
        if(arr[i] > 0) {
            A[j++] = i;
            arr[i]--;
        }else{
            i++;
        }

    }
    cout << "Printing sorted !" << endl;
    for(int i=0; i<ssize-1; i++) {
        cout << A[i] << endl;
    }



}
int main()
{
    int A[10] = {6,3,9,10,15,6,8,12,3,6};
    int maxEl = findMax(A,(sizeof(A)/sizeof(A[0])));
    cout << "Hi, max is " << maxEl<<endl;
    countSort(A,maxEl,(sizeof(A)/sizeof(A[0])));
    return 0;
}

