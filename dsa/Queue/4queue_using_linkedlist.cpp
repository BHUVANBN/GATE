//Queue using linked list
// *front points to the first element
// *rear points to the last element
//empty condition - front = rear = NULL
//full condition - when heap is full as linkedlist is dynamically created

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
class Queue{
    private:
    Node *Q;
    Node *front,*rear;
    public:
    Queue(){
        front = rear = NULL;
    }
    void enqueue(int x){
        Node *t = new Node;
        if(t == NULL) cout<<"heap is full";
        else{
            t->data = x;
            t->next = NULL;
            if(front == NULL)
                front = rear = t;
            else{
                rear->next = t;
                rear = t;
            }
        }
    }
    int dequeue(){
        Node *t = front;
        if(front == NULL) cout<<"queue is empty";
        int x = front->data;
        front = front->next;
        delete t;
        return x;   
    }
    void display(){
        Node *t = front;
        while(t!=NULL){
            cout<<t->data<<" ";
            t = t->next;
        }
        cout<<endl;
    }

};
int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}