//Array drawbacks- fixed size, not dynamic, eventhough we can use dynamic arrays in heap using pointer but arrays are not flexible
//Linked list is a dynamic data structure, and flexible in size, insert and delete operations are easy

//linkedlist is a collection of nodes where each node contains data and a pointer to the next node
/*
   |first|-------> |data|next| -> |data|next| -> |data|null| 
pointer in stack      node1          node2          node3 
*/

#include<stdio.h>
#include<iostream>
using namespace std;

struct Node{  //in c++ struct everything by default public, whereas in class everything by default in private
    int data;
    struct Node *next; //self referential structure
};
int main(){

    struct Node *first, *second ;
    first = new Node; // first = (struct Node*)malloc(sizeof(struct Node));
    first->data = 1;
    first->next = NULL;
    
    second = new Node;
    second->data = 2;
    second->next = NULL;
    first->next = second; //linking second node to first 

    //traversing linkedlist using while loop , for loop sed when length is known
    struct Node *P=first;
    while(P!=NULL){ //P becomes null when it donot points to any node i.e it reaches void space after last node
        cout<<P->data<<" ";
        P=P->next;
    }
    return 0;
}