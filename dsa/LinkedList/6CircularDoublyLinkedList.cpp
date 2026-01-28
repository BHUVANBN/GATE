//Circular Doubly Linked List is a type of doubly linked list in which the last node is connected to the first node circularly.
#include<iostream>
using namespace std;

class Node{
    public:
        Node *prev;
        int data;
        Node *next;
};
class CircularDoublyLinkedList{
    private:
        Node *head;
    public:
    CircularDoublyLinkedList(){
        head = NULL;
    }
    CircularDoublyLinkedList(int A[], int n){
        head = new Node;
        head->data = A[0];
        head->prev = head;
        head->next = head;
        Node *p = head;
        for(int i=1; i<n; i++){
            Node *t = new Node;
            t->data = A[i];
            t->prev = p;
            t->next = p->next;
            p->next = t;
            p = t;
        }
        p->next = head;
        head->prev = p;
    }
    int Length(){
        int len=0;
        if(head == NULL) return 0;
        Node *p = head;
        do{
            len++;
            p = p->next;
        }while(p != head);
        return len;
    }
    void Insert(int index, int x){
        if(index < 0 || index > Length()){
            return;
        }
        Node *t = new Node;
        t->data = x;
        
        if(head == NULL){
            head = t;
            head->prev = head;
            head->next = head;
            return;
        }
        
        if(index == 0){
            t->next = head;
            t->prev = head->prev;
            head->prev->next = t;
            head->prev = t;
            head = t;
        }
        else{
            Node *p = head;
            for(int i=0;i<index-1;i++){
                p = p->next;
            }
            t->next = p->next;
            t->prev = p;
            p->next->prev = t;
            p->next = t;
        }
    }
    int Delete(int index){
        if(index < 1 || index > Length() || head == NULL){
            return -1;
        }
        Node *p = head;
        
        if(index == 1){
            if(head->next == head){ //only one node
                int x = head->data;
                delete head;
                head = NULL;
                return x;
            }
            p = head;
            head = head->next;
            head->prev = p->prev;
            p->prev->next = head;
            int x = p->data;
            delete p;
            return x;
        }
        
        for(int i=1;i<index;i++){
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        int x = p->data;
        delete p;
        return x;
    }
    void Display(){
        Node *p = head;
        if(head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        do{
            cout<<p->data<<" ";
            p = p->next;
        }while(p != head);
        cout<<"\n";
    }
    void Reverse(){
        if(head == NULL || head->next == head) return;
        
        Node *p = head;
        Node *temp;
        do{
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = temp;
        }while(p != head);
        
        //head now points to the previous node (which was the last node)
        head = head->next;
    }
    ~CircularDoublyLinkedList(){
        if(head == NULL) return;
        Node *p = head;
        Node *q;
        do{
            q = p->next;
            delete p;
            p = q;
        }while(p != head);
    }
};
int main(){
    int A[] = {1,2,3,4,5,6};
    CircularDoublyLinkedList cdll(A,6);
    
    cout<<"Original list: ";
    cdll.Display();
    cout<<"Length: "<<cdll.Length()<<endl;
    
    cdll.Insert(3, 10);
    cout<<"After inserting 10 at index 3: ";
    cdll.Display();
    
    cdll.Insert(0, 20);
    cout<<"After inserting 20 at index 0: ";
    cdll.Display();
    
    int deleted = cdll.Delete(1);
    cout<<"After deleting node at index 1 (deleted value: "<<deleted<<"): ";
    cdll.Display();
    
    cdll.Reverse();
    cout<<"After reversing: ";
    cdll.Display();
    
    return 0;
}