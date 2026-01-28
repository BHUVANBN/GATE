//creating linked list using array
#include<stdio.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first,*second,*third; //creating a first pointer that points to first node

struct Node* createLinkedList(int A[], int n){
    struct Node *t, *last, *ptr;   //t is used to create new node and last is used to add new node
    ptr = new Node;
    ptr->data = A[0];
    ptr->next = NULL;
    last = ptr;
    for(int i = 1; i< n; i++ ){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return ptr;
}
void display(struct Node *p){//time complexity - O(n)
    cout<<"first pointer address: "<<first<<endl;
    while(p!=NULL){
        cout<<"data :"<<p->data<<" | ";
        cout<<"Current Address :"<<p<<" | ";
        cout<<"Next Address :"<<p->next<<endl;
        p=p->next;
    }
}
void RecursiveDisplay(struct Node *p){ //time complexity - O(n)
    if(p){
        cout<<p->data<<" ";  //if we change the order of printing and recurscive call the values are printed in descending order, i.e prints when returning
        RecursiveDisplay(p->next);
    }
}
//counting nodes - finding length of the list
int count(struct Node *p){ //time complexity - O(n)
    if(p){
        return count(p->next) + 1; //recursive call
    }
    return 0;
}
//sum of elements
int sum(struct Node *p){ //time complexity - O(n)
    if(p){
        return p->data + sum(p->next);
    }
    return 0;
}
//maximum element
int max(struct Node *p){ //time complexity - O(n)
    if(p){
        return max(p->next) > p->data ? max(p->next) : p->data;
    }
    return 0;
}
//searching in linkedlist
//we cant do binary search as linkedlist dont support random access to access middle 
//we use linear search to find element
Node* RecursiveSearch(struct Node *p, int key){ //time complexity - O(n)
    if(p){
        if(p->data == key){
            return p;
        }
        return RecursiveSearch(p->next, key);
    }
    return NULL;
}
//searching using while loop
Node* search(struct Node *p, int key){ //time complexity - O(n)
    while(p){
        if(p->data == key){
            return p;
        }
        p = p->next;
    }
    return NULL;
}
//improving linear search by transposing or move to head
Node* MoveToHeadSearch(struct Node *p, int key){
    //we use pointer q to follow ponter p to get the address of previous node
    Node *q = NULL;
    while(p){
        if(key==p->data){
            q->next = p->next; //now p is not connected to the list, q connects to the next node of p
            p->next = first; //p is now connected to first
            first = p; //p is now the first node
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
//inserting in linked list
//insert before first node
//insert in the middle after nth node
void insert(struct Node *p, int data, int pos){
    if(pos < 0 || pos> count(p)) return;
    struct Node *t; //temporary pointer to create a new node
    t = new Node;
    t->data = data;
    if(pos == 0){ //insert in the front 
        t->next = first;
        first = t;
    }
    else{
        for(int i=0; i<pos-1; i++){
            p = p->next;
        }//now the p is in the position where we want to insert
        t->next = p->next;
        p->next = t;
    }
}
//append - insert at last 
void append(struct Node *p, int data){
    struct Node *t; //temporary pointer to create a new node
    t = new Node;
    t->data = data;
    t->next = NULL;
    if(first == NULL){
        first = t;
    }
    else{
        while(p->next != NULL){
            p = p->next;
        } //p is in last node
        p->next = t;
    }
}
//insert node in sorted list 
void insertSorted(struct Node *p, int data){
    struct Node *t; //temporary pointer to create a new node
    t = new Node;
    t->data = data;
    t->next = NULL;
    struct Node *q = NULL;
    if(first == NULL){
        first = t;
    }
    else{
        while(p && p->data < data){
            q = p;
            p = p->next;
        }
        if(p == first){
            t->next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}
//deleting node from linked list
int deleteNode(struct Node *p, int pos){
    struct Node *q = NULL; //q is used to point to the previous node which we want to delete
    int x = -1; //to store the data of the node to be deleted
    if(pos < 1 || pos > count(p)) return -1;
    if(pos == 1){
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }
    else{
        for(int i=0; i<pos-1; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}
//check if thr list is sorted or not
bool isSorted(struct Node *p){
    int x = -32768; //minimum value of int
    while(p){
        if(p->data < x) return false;
        x = p->data;
        p = p->next;
    }
    return true;
}
//removing duplicates in a sorted linked list
void RmDup(struct Node *p){
    struct Node *q;
    while(p && p->next){
        q=p;
        p=p->next;
        if(p->data == q->data){
            q->next = p->next;
            delete p;
            p = q->next;
        }
    }
}
//Reversing linked list by reversing links
//reversing link is preferred because shifting only data(with many attributes) may not be possible in all cases
//sliding pointers - using 3 pointers r,q,p
void ReverseList(struct Node *p){
    struct Node *q = NULL, *r = NULL;
    while(p){
        r = q;          // r follows q
        q = p;          // q follows p
        p = p->next;    // p moves forward
        q->next = r; //links the q node to r node
    }
    first = q; //first ointer is pointing to q(last node as p is now null) now
}
//reversing linkedlist using recursion by reversing links
void ReverseListRecursive(struct Node *q, struct Node *p){
    if(p){
        ReverseListRecursive(p, p->next);
        p->next = q;
    }
    else{
        first = q;
    }
}
//concatination of two linked list- reach the end of the first linkedlink and points to the next linkedlist
void concat(struct Node *p, struct Node *second){
    while(p->next){
        p = p->next; //reaches the last node of the first linkedlist
    }
    p->next = second; //q is the head of the second linked list
    second = NULL;
}
//merging two sorted list into single sorted list
//using *third and *last pointers
//*third is used to add sorted nodes 
//*last is used to keep track of the last node in the merged list so that we can add more nodes to it
void mergeLinkedList(struct Node *first, struct Node *second){
    third = NULL;
    struct Node *last;
    while(first && second){ 
        if(first->data < second->data){
            if(third == NULL){
                third = last = first;
                first = first->next;
                last->next = NULL;
            }
            else{
                last->next = first;
                last = first;
                first = first->next;
                last->next = NULL;
            }
        }
        else{ //second->data < first->data
            if(third == NULL){
                third = last = second;
                second = second->next;
                last->next = NULL;
            }
            else{
                last->next = second;
                last = second;
                second = second->next;
                last->next = NULL;
            }
        }
    }
    if(first) last->next = first; //if second list is exhausted
    if(second) last->next = second; //if first list is exhausted
}
//To find the linkedlist is in loop or linear
//Linear LinkedList end with null
//Looped LinkedList end with other node in the same linkedlist
//using two pointers with different speeds(i.e one ptr moves one nnode at a time other two nodes at a time) somewhere they will meet if the linkedlist is looped
void isLoop(struct Node *p){
    struct Node *q = first;
    while(p && q){
        p = p->next;
        q = q->next;
        q = q ? q->next : NULL; //if q is not null then move it to next node otherwise keep it as null
        if(p == q){
            cout<<"Loop"<<endl;
            return;
        }
    }
    cout<<"Not Loop"<<endl;
}
int main(){
    int A[] = {1,2,3,4,5};
    first = createLinkedList(A,5);
    display(first);
    cout<<"\n";

    cout<<"Recursive Display: ";
    RecursiveDisplay(first);

    cout<<"\nCount: "<<count(first);
    cout<<"\nSum: "<<sum(first);
    cout<<"\nMax: "<<max(first);

    cout<<"\nSearch: "<<search(first, 3);
    cout<<"\nRecursive Search: "<<RecursiveSearch(first, 3);
    // cout<<"\nMove to Head Search: "<<MoveToHeadSearch(first, 3);
    // cout<<"After move to front "<<endl;
    // RecursiveDisplay(first);
    
    cout<<"\n";
    insert(first, 6, 5); //also used to create linkedlist from scratch
    RecursiveDisplay(first);

    cout<<"\n";
    append(first, 7);
    RecursiveDisplay(first);

    cout<<"\n";
    insertSorted(first, 3);
    RecursiveDisplay(first);
    
    cout<<"\n";
    int deletedValue = deleteNode(first, 1);
    cout<<"Deleted value: "<<deletedValue<<"\n";
    RecursiveDisplay(first);

    cout<<"\nsorted? :"<<isSorted(first);

    cout<<"\nRemoving duplicates: ";
    RmDup(first);
    RecursiveDisplay(first);

    cout<<"\nReversing linked list by reversing links: ";
    ReverseList(first);
    RecursiveDisplay(first);
    cout<<"\nReversing linked list by reversing links using recursion: ";
    ReverseListRecursive(NULL, first);
    RecursiveDisplay(first);
    
    int B[] = {1,4,6,8,10};
    second = createLinkedList(B,5); //creates a new linked list using local *ptr pointer inside the function and assigns it to second
    cout<<"\nSecond LinkedList: ";
    RecursiveDisplay(second);

    mergeLinkedList(first, second);
    cout<<"\nAfter merging two sorted linked lists: ";
    RecursiveDisplay(third);
    
    cout<<"\nIs Loop: ";
    isLoop(first);
    //creating loop
    //A -> B -> C -> D -> E
    //          |         |
    //          t1 <---- t2
    struct Node *t1, *t2;
    t1 = first->next->next; //t1 is pointing to C
    t2 = first->next->next->next->next; //t2 is pointing to E
    t2->next = t1; //creating loop
    cout<<"\nIs Loop: ";
    isLoop(first);
    return 0;
}