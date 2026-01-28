//Doubly linked list - linked list nodes with next and prev address and can be traversed bi-directionally
#include<iostream>
using namespace std;

class Node{
    public:
    Node *prev;
    int data;
    Node *next;
};
class DLinkedList{
    private:
        Node *first;
    public:
    DLinkedList(){first = NULL;}
    DLinkedList(int A[], int n){
        Node *t,*last;
        first = new Node;
        first->data = A[0];
        first->prev = NULL;
        first->next = NULL;
        last = first;
        for(int i =1;i<n;i++){
            t = new Node;
            t->data= A[i];
            t->prev=last;
            t->next=NULL;
            last->next=t;
            last = t;
        }

    }
    void Display(){
        Node *p=first;
        while(p){
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<"\n";
    }
    int Length(){
        int len=0;
        Node *p = first;
        while(p){
            len++;
            p=p->next;
        }
        return len;
    }
    void Insert(int index, int x){
        if(index < 0 || index > Length()){
            return;
        }
        Node *p = first;
        Node *t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = NULL;
        if(index == 0){
            t->next = first;
            first->prev = t;
            first = t;
        }
        else{
            for(int i=0;i<index-1;i++){
                p = p->next;
            }
            t->next = p->next;
            t->prev = p;
            if(p->next){
                p->next->prev = t;
            }
            p->next = t;
        }
    }
    int Delete(int index){
        if(index < 1 || index > Length()){
            return -1;
        }
        if(index == 1){
            Node *p = first;
            first = first->next; //first pointer now points to next node
            if(first){
                first->prev = NULL;
            }
            int x = p->data;
            delete p;
            return x;
        }
        Node *p = first;
        for(int i=1;i<index;i++){
            p = p->next; //move to the node which is to be deleted
        }
        p->prev->next = p->next;
        if(p->next){ //check if the node exists
            p->next->prev = p->prev;
        }
        int x = p->data;
        delete p;
        return x;
    }
    //reversing in doubly linked list is swapping the pointers of each node(i.e prev and next)
    void Reverse(){
        Node *p = first;
        Node *temp;        
        while(p){
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = p->prev; //after swapping the next is in prev
            if(p!=NULL && p->next==NULL){//after swapping if any node->next is NULL, it means it is the last node in original list, so make first points to it
                first = p;
            }
        }
    }
};
int main(){
    int A[] = {1,2,3,4,5,6};
    DLinkedList dl(A,6);
    dl.Display();
    cout<<"Length is: "<<dl.Length()<<endl;

    dl.Insert(3, 10);
    dl.Display();

    dl.Delete(1);
    dl.Display();

    dl.Reverse();
    dl.Display();

    return 0;
}