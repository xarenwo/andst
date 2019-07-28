#include <iostream>
#include <string.h>
using namespace std;
class Node {
public:
    char data;
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
    char pop();
    void Display();
    bool isEmpty();
    char peek();
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


char Stack::pop() {
    char x = -1;
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

char Stack::peek() {
    char x=-1;
    if(top!=NULL) {
        x=(char)top->data;
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

int isOperand(char x) {
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return 0;
    } else {
        return 1;
    }
}

int pre(char x) {
    if(x=='+' || x=='-') {
        return 1;
    }
    else if(x=='*' || x=='/') {
        return 2;
    } else {
        return 0;
    }
}


char *convertPostfix(Stack *stk,char *infix) {
    int i=0,j=0;
    cout << "Peeking into stack : " << stk->peek()  << endl;
    int len=strlen(infix);
    char *postfix = new char[sizeof(len+4)];
    while(infix[i]!='\0'){
        cout << "Peeking into stack : " << stk->peek() << endl;
        if(isOperand(infix[i])) {
            cout << "Peeking into stack : " << stk->peek() << endl;
            postfix[j++] = infix[i++];

        } else {
            cout << "Peeking into stack : " << stk->peek() << endl;
            if(pre(infix[i]) > pre(stk->peek())) {
                stk->push(infix[i++]);
            } else {
                postfix[j++] = stk->pop();
            }
        }
    }
    while(!stk->isEmpty()) {
        cout << "Stack is not empty " << !stk->isEmpty() << endl;
        postfix[j++]=stk->pop();
    }
    postfix[j] = '\0';

    return postfix;
}

int main() {

    auto *stk = new Stack;
    char *infix = "a+b*c";;
    stk->push('#');
    stk->push('$');
    cout <<" Setting up postfix ...." <<endl;
    char *postfix=convertPostfix(stk,infix);
    cout <<"Printing postfix ..." << endl;
    cout << "Final postfix : " << postfix <<endl;

    return 0;

}
