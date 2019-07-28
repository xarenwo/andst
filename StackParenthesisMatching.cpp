#include <iostream>
#include <string.h>
using namespace std;
class Node {
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;
public:
    Stack() {
        top=NULL;
    }
    void push(int x);
    int pop();
    void Display();
    bool isEmpty();
};

bool Stack::isEmpty() {
    if(top==NULL) {
        return true;
    } else {
        return false;
    }
}
void Stack::push(int x) {
    Node *t = new Node;
    if(t==NULL) {
        cout << "Stack is full !" <<endl;
    } else {
        t->data=x;
        t->next=top;
        top=t;
    }
}


int Stack::pop() {
    int x = -1;
    if(top==NULL) {
        cout << "Stack is empty !" <<endl;

    } else {
        x = top->data;
        Node *t = top;
        top=top->next;
        delete t;

    }

    return x;
}

void Stack::Display() {
    Node *p = top;
    while(p!=NULL) {
        cout <<p->data<<" ";
        p=p->next;
    }
    cout << endl;
}


void ParMatching(Stack *stk) {
    //((a+b)*(c-d))
    string Par = "((a+b)*(c-d)";
    for(int i=0; i<Par.size();i++) {
        if(Par[i] =='(') {
            cout << "Top is now " << Par[i] << endl;
            stk->push(Par[i]);
        } else if(Par[i] == ')') {
            if(stk->isEmpty()) {
                cout << "No element to pop !\n"<<endl;
            } else {
                cout << "Top is now " << Par[i] << endl;
                stk->pop();
            }
        }



    }
    if(stk->isEmpty()) {
        cout <<"Parenthesis match !" <<endl;
    } else {
        cout <<"Parenthesis mismatch !" << endl;
    }


}

int main() {

    Stack stk;
    ParMatching(&stk);
    cout << "Stack is empty ? " << stk.isEmpty() << endl;
}
