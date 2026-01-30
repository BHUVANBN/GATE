#include<iostream>
using namespace std;

class Queue{
    private:
    int size;
    int front;
    int rear;
    int *Q;
    public:
    Queue(){
        front = rear = -1; 
        size = 10; 
        Q = new int[size];
    }
    Queue(int size){
        this->size = size;
        front = rear = -1;
        Q = new int[size];
    }
    void enqueue(int x){
        if(rear == size-1) cout<<"queue is full";
        else{
            rear++;
            Q[rear] = x;
        }
    }
    int dequeue(){
        int x = -1;
        if(front == rear) cout<<"queue is empty";
        else{
            front++;
            x = Q[front];
        }
        return x;
    }
    void display(){
        for(int i = front+1; i<=rear; i++){
            cout<<Q[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Queue q(10);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    
    q.dequeue();
    q.display();

    return 0;
}