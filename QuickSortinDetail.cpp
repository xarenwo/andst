#include <iostream>
using namespace std;
int swap(int *i,int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}
int Partition(int *A, int low, int high) {
    int pivot = A[high];
    int i = (low-1); // index of highest element
    for(int j=low; j<=high-1; j++) {
        if(A[j] <= pivot) { // increment J until we reach an element that is bigger or equal than the pivot,
            // once reached that index, we know i++ is the
            /*
             * We start from the leftmost element and keep track of index of smaller (or equal to) elements as i.
             * While traversing, if we find a smaller element, we swap current element with arr[i]. Otherwise we ignore current element.
             */
            cout << "####################\n A[j]: "  << A[j] << " is <= " << pivot << "\n";
            i++;
            cout << "Swapped small element A[j] with i, i was " << A[i-1] << " and it is now " << A[j] << "\n Instead of  " <<A[j]<<" we put "<< A[i] << "\n";
            cout << "A[j]: " << A[j] << " A[i++]: " << A[i] << "\n#######################\n";
            swap(&A[j],&A[i]);
            // When we are not replacing smaller element in the i index, it means we reached a number > pivot, so we go on until we find more
            // that way we can put all numbers < pivot on the left

        } else {
            cout << " A[j]: " << A[j] << " is not <= " << pivot << "\n Skipping to " << A[j+1] << "\n";
        }
    }
    swap(&A[i+1],&A[high]);
    cout << "->->-> Partition is " << i+1 << " : " << A[i+1] << "\n Element on left is " << A[i] << " and on right is " << A[i+2] << "\n";
    cout << "Array is now : ";
    for(int x=low; x<high+1; x++) {
        cout << A[x] << " ";
    }
    cout << "\n";
    return i+1;
}
// int A[] = {6,42,124,5,61,24,5,40};

void QuickSort(int *A, int low, int high) {
    if(low < high) {
        int pIndex = Partition(A,low,high);
        // Elements to the left are smaller and elements to the right are bigger
        // Leave pIndex alone as it is sorted, take care of left and right partitions
        QuickSort(A,low,pIndex-1); // Recursively take care of the numbers to the left of the partition index
        QuickSort(A,pIndex+1,high); // // Recursively take care of the numbers to the right of the partition index
    }
}
int main() {

            // {6,5,24,5,40,124,42,61}
            // {6,5,24,5}
            // {5,6,24,5}
            // {5,5,24,6}
            // {24,6}
            // {6,24}
            
            // {124,42,61}
            // {42,124,61}
            // {42,61,124}
            // {5,5,6,24,40,42,61,124}
            
            
    int A[] = {6,42,124,5,61,24,5,40};
    int arr_size = sizeof(A)/sizeof(A[0]);
    std::cout  << "Size is : " << arr_size << "\n";
    QuickSort(A,0,arr_size-1);
    for(int i=0;i<arr_size;i++) {
        std::cout << A[i] << "\n";
    }
    return 0;
}
