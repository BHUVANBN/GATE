//Stack using linked list
//push and pop operations are performed at the front of linked list
//top pointer points to the first node of linked list
//empty condition: top == NULL
//full condition: as linked list is dynamic, it can grow as needed until heap of the system is full
/*
      Push 
        ↓
    top----->|data|next|----->|data|next|------>|data|null|

*/

#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
}*top =NULL;

void push(int x){
    Node *t = new Node;
    if(t == NULL){
        cout<<"Stack overflow"<<endl;
    }
    else{
        t->data = x;   
        t->next = top; //top is the previous node 
        top = t;
    }
}
int pop(){
    if(top == NULL){
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    else{
        Node *t = top;  //here top and t points to first node 
        top = top->next; //top points to second node 
        int x = t->data; //first node data is assigned to x
        delete t; //first node is deleted
        return x; //first node data is returned
    }
}
void display(){
    struct Node *p = top;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
int main(){
    //stack is initially just a top pointer pointing to NULL
    push(10);
    push(20);
    push(30);
    display();
    cout<<"Popped element: "<<pop()<<endl;
    display();
    return 0;
}
