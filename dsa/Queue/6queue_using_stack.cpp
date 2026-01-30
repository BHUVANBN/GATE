//Queue using Stack
//Queue can be implemented using two stacks
//Method 1: Make enqueue operation costly
//Method 2: Make dequeue operation costly

//Method 1: Make enqueue operation costly
//1. While stack1 is not empty, push everything from stack1 to stack2
//2. Push x to stack1
//3. Push everything back to stack1
//Time complexity: O(n) for enqueue, O(1) for dequeue

//Method 2: Make dequeue operation costly
//1. If both stacks are empty then error
//2. If stack2 is empty, while stack1 is not empty, push everything from stack1 to stack2
//3. Pop the element from stack2 and return it
//Time complexity: O(1) for enqueue, O(n) for dequeue

#include<iostream>
#include<stack>
using namespace std;

class QueueUsingStacks{
    private:
    stack<int> stack1;
    stack<int> stack2;
    
    public:
    QueueUsingStacks(){
        //constructor
    }
    
    //Method 1: Make enqueue operation costly
    void enqueueCostly(int x){
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        
        stack1.push(x);
        
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
    
    int dequeueCostly(){
        if(stack1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        
        int x = stack1.top();
        stack1.pop();
        return x;
    }
    
    //Method 2: Make dequeue operation costly
    void enqueueEfficient(int x){
        stack1.push(x);
    }
    
    int dequeueEfficient(){
        if(stack1.empty() && stack2.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        int x = stack2.top();
        stack2.pop();
        return x;
    }
    
    //Common methods
    bool isEmpty(){
        return stack1.empty() && stack2.empty();
    }
    
    int front(){
        if(stack1.empty() && stack2.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        
        if(!stack2.empty()){
            return stack2.top();
        } else {
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            return stack2.top();
        }
    }
    
    int size(){
        return stack1.size() + stack2.size();
    }
    
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        
        cout<<"Queue elements: ";
        
        //Display elements in queue order
        stack<int> temp1 = stack1;
        stack<int> temp2 = stack2;
        
        //First display elements from stack2 (they are in correct order)
        while(!temp2.empty()){
            cout<<temp2.top()<<" ";
            temp2.pop();
        }
        
        //Then display elements from stack1 in reverse order
        stack<int> reverseStack;
        while(!temp1.empty()){
            reverseStack.push(temp1.top());
            temp1.pop();
        }
        
        while(!reverseStack.empty()){
            cout<<reverseStack.top()<<" ";
            reverseStack.pop();
        }
        
        cout<<endl;
    }
};

int main(){
    cout<<"=== Method 1: Enqueue Costly ==="<<endl;
    QueueUsingStacks q1;
    
    q1.enqueueCostly(10);
    q1.enqueueCostly(20);
    q1.enqueueCostly(30);
    
    cout<<"Queue after enqueuing 10, 20, 30: ";
    q1.display();
    
    cout<<"Dequeuing: "<<q1.dequeueCostly()<<endl;
    cout<<"Dequeuing: "<<q1.dequeueCostly()<<endl;
    
    q1.enqueueCostly(40);
    cout<<"Queue after enqueuing 40: ";
    q1.display();
    
    cout<<"Dequeuing: "<<q1.dequeueCostly()<<endl;
    cout<<"Dequeuing: "<<q1.dequeueCostly()<<endl;
    
    cout<<"\n=== Method 2: Dequeue Costly ==="<<endl;
    QueueUsingStacks q2;
    
    q2.enqueueEfficient(10);
    q2.enqueueEfficient(20);
    q2.enqueueEfficient(30);
    
    cout<<"Queue after enqueuing 10, 20, 30: ";
    q2.display();
    
    cout<<"Dequeuing: "<<q2.dequeueEfficient()<<endl;
    cout<<"Dequeuing: "<<q2.dequeueEfficient()<<endl;
    
    q2.enqueueEfficient(40);
    cout<<"Queue after enqueuing 40: ";
    q2.display();
    
    cout<<"Dequeuing: "<<q2.dequeueEfficient()<<endl;
    cout<<"Dequeuing: "<<q2.dequeueEfficient()<<endl;
    
    cout<<"\n=== Testing other operations ==="<<endl;
    QueueUsingStacks q3;
    
    q3.enqueueEfficient(100);
    q3.enqueueEfficient(200);
    q3.enqueueEfficient(300);
    
    cout<<"Queue size: "<<q3.size()<<endl;
    cout<<"Front element: "<<q3.front()<<endl;
    cout<<"Is queue empty: "<<(q3.isEmpty() ? "Yes" : "No")<<endl;
    
    q3.display();
    
    return 0;
}
