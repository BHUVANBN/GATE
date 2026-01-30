//Drawback of the Queue - 
// empty space is wasted as the deletion happens from the front and elements are not shifted to the left
// even though  there is space in the front of the queue , if the rear is at the end of the array the queue is full
// every location is used only once - no reuse
// when the front and rear points to the last location of the array, the queue is full as well as empty 

//Solutions- 
//Resetting the pointers - at any location if the front == rear, reinitialize the front and rear to -1, i.e bring back the pointer to the initial state
//                         it only applies when queue is fully empty, not if there is an empty space in the front and rear is not pointing to same location of front

//Circular queue - 
//  front and rear moves circulalry, i.e once the rear reaches the end of the array, it moves to the start of the array, and front also moves to the start of the array once it reaches the end of the array
//  here rear = front = 0, initialization
//  use mod operation to obtain the circular effect, i.e come back to initial place
/*eg: lets say size is 5, 
      then rear = (rear+1)%5, front = (front+1)%5
      |rear   | (rear +1)%size |
      | 0     | (0+1)%5  = 1   | //rear moves to the next location
      | 1     | (1+1)%5  = 2   |
      | 2     | (2+1)%5  = 3   |
      | 3     | (3+1)%5  = 4   |
      | 4     | (4+1)%5  = 0   | //rear moves to initial location
      | 0     | (0+1)%5  = 1   | //rear moves to the next location
*/
//so (rear+1)%size is used to move to next location

//(rear+1)%size == front means queue is full
//(front+1)%size == rear means queue is empty
#include<iostream>
using namespace std;
class CircularQ{
    private:
    int size;
    int front;
    int rear;
    int *CQ;
    public:
    CircularQ(){
        front = rear = 0;
        size = 10;
        CQ = new int[size];
    }
    CircularQ(int size){
        front = rear = 0;
        this->size = size;
        CQ = new int[size];
    }
    void enqueue(int x){
        if((rear+1)%size == front) cout<<"queue is full"; //queue is full when front is in the next location of rear
        else{
            rear = (rear+1)%size; //move rear to the next location i.e empty location
            CQ[rear] = x; //store the element at the rear pointer
        }
    }
    int dequeue(){
        int x = -1;
        if(front == rear) cout<<"queue is empty";
        else{
            front = (front+1)%size; //move front to the next location from empty location
            x = CQ[front]; //take out the element which the front pointer points to
        }
        return x;
    }
    void display(){
        for(int i = front+1; i!=(rear+1)%size; i=((i+1)%size)){
            cout<<"|"<<i<<":"<<CQ[i]<<"| ";
           
        }
        cout<<endl;
    }
    
};
int main(){
    CircularQ cq(4);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cout<<"display format: |index:element|"<<endl;
    cq.display();
    cq.dequeue();
    cq.display();
    cq.enqueue(50);
    cq.display();

    //in the size of 4 , only 3 elements can be stored as front always points to empty location before first element
    return 0;
}