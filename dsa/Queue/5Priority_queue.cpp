//Priority Queue - queue where the element with highest priority is at the front
//used in Operating System while scheduling processes

//two types - Limited set of priorities and Unlimited set of priorities(elements itself is the priority)

//Limited set of priorities
//eg:
//priority 1 - highest
//priority 2
//priority 3 - lowest
//so 3 queues are used and deleted from the highest priority queue then next highest priority queue and so on...

//element itself is the priority
//eg: , 7, 3, 5, 6, 4, 1, 2
//so 7 is the highest priority and 1 is the lowest priority

#include<iostream>
using namespace std;

struct Node{
    int data;
    int priority;
    Node *next;
};

class PriorityQueue{
    private:
    Node *front;
    
    public:
    PriorityQueue(){
        front = NULL;
    }
    
    void enqueue(int x, int priority){
        Node *t = new Node;
        if(t == NULL){
            cout<<"Memory allocation failed"<<endl;
            return;
        }
        t->data = x;
        t->priority = priority;
        t->next = NULL;
        
        if(front == NULL || priority < front->priority){
            t->next = front;
            front = t;
        } else {
            Node *p = front;
            while(p->next != NULL && p->next->priority <= priority){
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }
    
    int dequeue(){
        int x = -1;
        if(front == NULL){
            cout<<"Priority Queue is empty"<<endl;
            return x;
        }
        
        Node *p = front;
        x = p->data;
        front = front->next;
        delete p;
        return x;
    }
    
    void display(){
        Node *p = front;
        while(p != NULL){
            cout<<"Data: "<<p->data<<", Priority: "<<p->priority<<" -> ";
            p = p->next;
        }
        cout<<"NULL"<<endl;
    }
    
    bool isEmpty(){
        return front == NULL;
    }
};

class LimitedPriorityQueue{
    private:
    static const int NUM_PRIORITIES = 3;
    Node *queues[NUM_PRIORITIES];
    
    public:
    LimitedPriorityQueue(){
        for(int i = 0; i < NUM_PRIORITIES; i++){
            queues[i] = NULL;
        }
    }
    
    void enqueue(int x, int priority){
        if(priority < 1 || priority > NUM_PRIORITIES){
            cout<<"Invalid priority. Use 1 (highest) to "<<NUM_PRIORITIES<<" (lowest)"<<endl;
            return;
        }
        
        Node *t = new Node;
        if(t == NULL){
            cout<<"Memory allocation failed"<<endl;
            return;
        }
        t->data = x;
        t->priority = priority;
        t->next = NULL;
        
        int index = priority - 1;
        if(queues[index] == NULL){
            queues[index] = t;
        } else {
            Node *p = queues[index];
            while(p->next != NULL){
                p = p->next;
            }
            p->next = t;
        }
    }
    
    int dequeue(){
        int x = -1;
        for(int i = 0; i < NUM_PRIORITIES; i++){
            if(queues[i] != NULL){
                Node *p = queues[i];
                x = p->data;
                queues[i] = queues[i]->next;
                delete p;
                return x;
            }
        }
        cout<<"All priority queues are empty"<<endl;
        return x;
    }
    
    void display(){
        for(int i = 0; i < NUM_PRIORITIES; i++){
            cout<<"Priority "<<(i+1)<<": ";
            Node *p = queues[i];
            while(p != NULL){
                cout<<p->data<<" ";
                p = p->next;
            }
            if(queues[i] == NULL){
                cout<<"Empty";
            }
            cout<<endl;
        }
    }
    
    bool isEmpty(){
        for(int i = 0; i < NUM_PRIORITIES; i++){
            if(queues[i] != NULL){
                return false;
            }
        }
        return true;
    }
};

int main(){
    cout<<"=== Priority Queue (Element as Priority) ==="<<endl;
    PriorityQueue pq;
    
    pq.enqueue(10, 3);
    pq.enqueue(20, 1);
    pq.enqueue(30, 2);
    pq.enqueue(40, 1);
    pq.enqueue(50, 2);
    
    cout<<"Priority Queue after enqueuing elements:"<<endl;
    pq.display();
    
    cout<<"Dequeuing elements (highest priority first):"<<endl;
    while(!pq.isEmpty()){
        cout<<"Dequeued: "<<pq.dequeue()<<endl;
    }
    
    cout<<"\n=== Limited Priority Queue (3 priority levels) ==="<<endl;
    LimitedPriorityQueue lpq;
    
    lpq.enqueue(100, 2);
    lpq.enqueue(200, 1);
    lpq.enqueue(300, 3);
    lpq.enqueue(400, 1);
    lpq.enqueue(500, 2);
    lpq.enqueue(600, 3);
    
    cout<<"Limited Priority Queue after enqueuing elements:"<<endl;
    lpq.display();
    
    cout<<"Dequeuing elements (highest priority queue first):"<<endl;
    while(!lpq.isEmpty()){
        cout<<"Dequeued: "<<lpq.dequeue()<<endl;
    }
    
    return 0;
}