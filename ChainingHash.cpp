#include <iostream>
using namespace std;
typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node *first=NULL;
void SortedInsert(Node **H,int x) {
    Node *t,*q=NULL,*p=*H;

    t=new Node;
    t->data=x;
    t->next=NULL;

    if(*H==NULL){
        *H=t;
    } else {
        while(p && p->data<x) {
            q=p;
            p=p->next;
        }
        if(p==*H) {
            t->next = *H;
            *H = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}

int hashKey(int key) {
    return key%10;
}

void Insert(Node *H[], int key){
    int index = hashKey(key);
    SortedInsert(&H[index],key);
}

Node *Search(Node *p,int key) {
    while(p!=NULL) {
        if(key==p->data) {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

int main() {
    //Create hashtable
    Node *HT[10];
    Node *temp;
    int i;
    for(i=0;i<10;i++){
        HT[i] = NULL;
    }

    Insert(HT,12);
    Insert(HT,22);
    Insert(HT,42);
    Insert(HT,52);
    temp = Search(HT[hashKey(22)],32);
    cout << temp->data << endl;
    return 0;
}
