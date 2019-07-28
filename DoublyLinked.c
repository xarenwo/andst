#include <stdio.h>
#include <stdlib.h>
struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[],int n) {
    struct Node *t,*last;
    int i;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for(i=1;i<n;i++) {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }


}


void display(struct Node *p) {
    while(p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int Length(struct Node *p) {
    int len=0;
    while(p) {
        len++;
        p=p->next;
    }
    return len;
}

void InsertNode(struct Node *node, int pos, int x) {
    // Inserting before first node (index 0)
    struct Node *newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    if(pos==1) {
        newNode->data=x;
        newNode->next=newNode->prev=NULL;
        newNode->next = first;
        first->prev=newNode;
        first=newNode;
    } else {
        struct Node *q=NULL;
        for(int i=1; i<pos-1; i++) {
            node=node->next;

        }

        newNode->data=x;
        newNode->next = node->next;
        newNode->prev = node;
        if(node->next) {
            node->next->prev=newNode;
        }
        node->next = newNode;
    }



}

void Delete(struct Node *node,int pos){
    if(pos==1) {
        node=first;
        first=first->next;
        if(first){
            first->prev=NULL;
        }
        int data = node->data;
        free(node);
    } else {
        for(int i=0;i<pos-1;i++) {
            node=node->next;
        }
        node->prev->next=node->next;
        if(node->next) {
            node->next->prev=node->prev;
        }

        int data = node->data;
        free(node);
    }
}


void Reverse(struct Node *node) {
    node=first;
    struct Node *temp=NULL;
    while(node) {
        temp=node->next;
        node->next = node->prev;
        node->prev=temp;
        node=node->prev;
        if(node!=NULL && node->next == NULL) {
            first=node;
        }
    }
}

int main() {
    int A[]={12,24,33,47,59};
    create(A,5);
    printf("\n Length is %d \n",Length(first));
    display(first);
    InsertNode(first,3,32);
    display(first);
    Delete(first,2);
    display(first);
    Reverse(first);
    display(first);
    return 0;
}
