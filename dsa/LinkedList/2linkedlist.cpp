#include<stdio.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first = NULL; //creating a first pinter that points to first node

void createNode(int A[], int n){
    struct Node *t, *last;   //t is used to create new node and last is used to add new node
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i< n; i++ ){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(struct Node *p){
    cout<<"first pointer address: "<<first<<endl;
    while(p!=NULL){
        cout<<"data :"<<p->data<<" | ";
        cout<<"Current Address :"<<p<<" | ";
        cout<<"Next Address :"<<p->next<<endl;
        p=p->next;
    }
}
int main(){
    int A[] = {1,2,3,4,5};
    createNode(A,5);
    display(first);
    return 0;
}