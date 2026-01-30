//DE queue - double ended queue
//insertion and deletion can be done from both ends

//front insertion - insert in the front(empty location) and decrement the front pointer
//front deletion - delete from the front and increment the front pointer
//rear insertion -increment the rear pointer and insert the element
//rear deletion - delete from the rear and decrement the rear pointer

//insert restricted DEqueue - front insertion is not allowed
//delete restricted DEqueue - rear deletion is not allowed

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

class DEQueue{
    private:
    Node *front;
    Node *rear;
    
    public:
    DEQueue(){
        front = rear = NULL;
    }
    
    void insertFront(int x){
        Node *t = new Node;
        if(t == NULL){
            cout<<"Memory allocation failed"<<endl;
            return;
        }
        t->data = x;
        t->next = NULL;
        t->prev = NULL;
        
        if(front == NULL){
            front = rear = t;
        } else {
            t->next = front;
            front->prev = t;
            front = t;
        }
    }
    
    void insertRear(int x){
        Node *t = new Node;
        if(t == NULL){
            cout<<"Memory allocation failed"<<endl;
            return;
        }
        t->data = x;
        t->next = NULL;
        t->prev = NULL;
        
        if(rear == NULL){
            front = rear = t;
        } else {
            rear->next = t;
            t->prev = rear;
            rear = t;
        }
    }
    
    int deleteFront(){
        int x = -1;
        if(front == NULL){
            cout<<"DEQueue is empty"<<endl;
            return x;
        }
        
        Node *p = front;
        x = p->data;
        
        if(front == rear){
            front = rear = NULL;
        } else {
            front = front->next;
            front->prev = NULL;
        }
        
        delete p;
        return x;
    }
    
    int deleteRear(){
        int x = -1;
        if(rear == NULL){
            cout<<"DEQueue is empty"<<endl;
            return x;
        }
        
        Node *p = rear;
        x = p->data;
        
        if(front == rear){
            front = rear = NULL;
        } else {
            rear = rear->prev;
            rear->next = NULL;
        }
        
        delete p;
        return x;
    }
    
    void display(){
        Node *p = front;
        while(p != NULL){
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }
    
    bool isEmpty(){
        return front == NULL;
    }
};

int main(){
    DEQueue dq;
    
    cout<<"Inserting at rear: 10, 20, 30"<<endl;
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertRear(30);
    dq.display();
    
    cout<<"Inserting at front: 5, 0"<<endl;
    dq.insertFront(5);
    dq.insertFront(0);
    dq.display();
    
    cout<<"Deleting from front: "<<dq.deleteFront()<<endl;
    dq.display();
    
    cout<<"Deleting from rear: "<<dq.deleteRear()<<endl;
    dq.display();
    
    return 0;
}

