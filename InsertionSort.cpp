#include <iostream>
#include<random>
#include <chrono>
using namespace std;

// Insertion sort
// Credits to geeksforgeeks.org for help
void Swap(int* x, int* y) {
    int temp = *y;
    *y = *x;
    *x = temp;
}

default_random_engine dre (chrono::steady_clock::now().time_since_epoch().count());     // provide seed
int random (int lim)
{
    uniform_int_distribution<int> uid {0,lim};   // help dre to generate nos from 0 to lim (lim included);
    return uid(dre);    // pass dre as an argument to uid to generate the random no
}

typedef struct Node {
    int data;
    struct Node *next;
} Node;



void InsertSortArray(int *A, int x, int n) {
    int i,k,j;
    for(i=1; i<n;i++) {
        k = A[i];
        j = i-1;
        /*
         If the element in the array is bigger than i-1, just shift elements to the next position
         If element is smaller, then stop the loop, we found the next element that is smaller than the one we have,
         so just insert it at i+1, as i+1 is empty because of shifting
        */

        while(j>=0 && A[j] > k) {
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = k;
    }
}
void sortedInsert(Node ** head, Node *new_node){
    Node* current;
    //  If exists element and the data in it is bigger or equal than the node we want to insert
    if(*head == NULL || (*head)->data >= new_node->data) {
        // Point the new node to the head
        new_node->next = *head;
        //  Move head to new_node
        *head = new_node;
        // This case was for our first element does not exist or if the current element is same as our inserted element
    } else {
        // Continue with elements and assign current as head of the list
        current = *head;
        //  While there is a next element and the next element's data is smaller than our new node
        while(current->next != NULL && current->next->data < new_node->data) {
            //  Move current to the next element
            current = current->next;
        }
        //  When we found an element that is smaller than our new_node
        //  Point the link of new_node to the new element
        new_node->next = current->next;
        //  Set next element as our new node
        current->next = new_node;
    }
}

// Use this function to create a copy of the linked list, sort it and return the head of the list
void InsertSortList(Node **head) {
    Node *sorted = NULL;
    Node *current = *head;

    while(current != NULL) {
        Node *next = current->next;
        sortedInsert(&sorted,current);

        current = next;
    }

    *head = sorted;

}

void push(Node** head, int n) {
    Node * new_node = new Node;
    new_node->data = n;
    new_node->next = (*head);
    *head = new_node;
}

void printList(Node *head) {
    Node *temp = NULL;
    temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main() {
    Node *head = NULL;
    for(int i=0; i<100; i++) {
        int rr = random(1000);
        push(&head,rr);
    }
//    push(&head,2);
//    push(&head,6);
//    push(&head,1);
//    push(&head,99);
//    push(&head,24);
    printList(head);
    InsertSortList(&head);
    cout << endl;
    printList(head);
    /*
    int A[30] = {0};

    for(int i = 0; i<20; i++) {
        int rr = random(100);
        cout << "Random is : " << rr << endl;
        cout << "Inserting : " << rr << endl;
        A[i] = rr;
    }
    InsertSortArray(A,0,20);



    cout << endl << "Displaying ... " << endl;
    for(int i=0;i<20;i++) {
        cout << A[i] << endl;
    }
    */


}
