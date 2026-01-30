//Queue is a FIFO(first in first out) data structure
//eg: used in printers, railways, etc
//insertion is done at rare end
//deletion is done at front end
/*

    deletion/dequeue<------| | | | | | | | |<---insertion/enqueue
                        front            rear
*/
//queue is implemented using array or linked list
//data - space for storing, front, rear
//operations - enqueue(x), dequeue(), isFull(), isEmpty(), first(), last()

//array implementation
//rear/front = -1 or front == rear (empty) //front points not to the first element , it points to the prev of first element i.e empty place
//rear = size-1 (full)

//using sigle pointer(rear) - it takes O(1) time for enqueue but O(n) time for dequeue,
//                             because when we remove an element from the front, we have to shift all the elements to the left
//using double pointer(front, rear) - it takes O(1) time for both enqueue and dequeue
//                              here we move the front pointer to the right when we remove an element from the front and rear pointer to the left when we add an element at the rear

#include<iostream>
using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new int[q->size];
}
void enqueue(struct Queue *q, int x){
    if(q->rear == q->size-1) cout<<"queue is full";
    else{
        q->rear++; //first move the rear pointer to the right from empty place
        q->Q[q->rear] = x; //then store the element at the rear pointer
    }
}
int dequeue(struct Queue *q){
    int x = -1;
    if(q->front == q->rear) cout<<"queue is empty";
    else{
        q->front++; //first move the front pointer to the right from empty place
        x = q->Q[q->front]; //then take out the element which the front pointer points to
    }
    return x;
}
void display(struct Queue q){
    for(int i = q.front+1; i<=q.rear; i++){
        cout<<q.Q[i]<<" ";
    }
    cout<<endl;
}
int main(){
    struct Queue q;
    cout<<"enter the size: ";
    cin>>q.size;
    create(&q, q.size);

    enqueue(&q,2);
    enqueue(&q,4);
    enqueue(&q,6);
    display(q);

    dequeue(&q);
    display(q);
    return 0;
}