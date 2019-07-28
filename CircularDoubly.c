#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node *getNewNode(int x) {
    struct Node *newNode = malloc(sizeof(*newNode));
    newNode->data = x;
    newNode->prev=newNode->next=NULL;
    return newNode;
}

void *CreateCircular(Node *list, int n) {
    struct Node *t,*last;
    int i;
    if(!list) { // no elements
        list = getNewNode(n);
        list->prev = list;
        list->next = list;

    } else if(list->prev ==list) { // one element
        list->prev =getNewNode(n);
        list->next = list->prev;
        list->prev->next = list;
        list->prev->prev=list;
    } else {
        list->prev->next = getNewNode(n);
        list->prev->next->prev = list->prev;
        list->prev= list->prev->next;
        list->prev->next = list;
    }
    return list;


}

int Length(Node *p) {
    Node *temp = p;
    int len=0;
    do {
        len++;
        temp=temp->next;
    } while(temp->next!=p);
    return len;
}

void DisplayCircular(Node *list) {
    Node *temp = list;
    printf("\nEntering display \n");
    printf("Length is %d \n", Length(list));
    for(int i=0; i<Length(list);i++) {
        printf("%d ",temp->data);
        temp=temp->next;
    }


    printf("\nExiting display \n");
}



void Delete(Node *list,int pos){
    if(pos==1) {
        Node *temp = list;
        temp=temp->next;
        printf("Temp->Prev %d\n Temp->Next %d\n List->Prev %d\nList->Next %d\n",temp->prev->data,temp->next->data,list->prev->prev->data,list->next->data);
        temp->prev = list->prev->prev;
        list->prev->prev = temp;
        int datax = list->data;

        free(list);
        *list = *temp;



        //node->prev=list;

    } else {
        for(int i=0;i<pos-1;i++) {
            list=list->next;
        }
        list->prev->next=list->next;
        if(list->next) {
            list->next->prev=list->prev;
        }

        int data = list->data;
        free(list);

    }
}




int main() {
    int n;
    Node *list = NULL;
    n=5;
    int A[] = {1,2,3,4,5};

    for(int i=0; i<=n; i++ ) {
        list = CreateCircular(list,A[i]);
    }

    DisplayCircular(list);
    printf("Length is %d \n",Length(list));
    Delete(list,1);
    DisplayCircular(list);


    return 0;
}
