//Stack is a LIFO(Last in First Out) data structure 
//ADT of a stack gives the data representation and the operations that can be performed on the data
//*top pointer to point to the top element index
//Operations: Push(x), Pop(), Peek(index), StackTop(), isEmpty(), isFull()
//all functions are O(1)
//counts from top of stack
/*
          idx         <--- push(4) 
      *top 2   |   3    |---> pop() //removes the top element
           1   |   2    |
           0   |___1____|
          -1
    
    Uses of stack
        - undo/redo features in text editors
        - backtracking algorithms
        - calling functions - recursion calls
        - stack of plates
*/
//implemented using array or linkedlist

//Array implementation - we need an Array, size, top pointer
#include<iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *stack; //pointer to an array created dynamically in heap
};
void createStack(Stack *st){
    cout<<"Enter the size of stack: ";
    cin>>st->size;
    st->stack = new int[st->size];
    st->top = -1;
}
void display(Stack st){
    for(int i = st.top; i >= 0; i--){
        cout<<st.stack[i]<<" ";
    }
    cout<<endl;
}
void push(Stack *st, int x){
    if(st->top == st->size - 1){ //stack full condition
        cout<<"Stack overflow"<<endl;
    }
    else{
        st->top++;
        st->stack[st->top] = x;
    }
}
int pop(Stack *st){
    int x = -1;
    if(st->top == -1){ //stack empty condition
        cout<<"Stack underflow"<<endl;
    }
    else{
        x = st->stack[st->top];
        st->top--;
    }
    return x;
}
//peak to get the element at a given index
//but the index is from top of stack must obtained 
//for that formula: index = top-index+1
int peek(Stack st, int index){
    if(index <= 0 || index > st.top+1){
        cout<<"Invalid index"<<endl;
        return -1;
    }
    return st.stack[st.top-index+1];   
}
int StackTop(Stack st){
    if(st.top == -1){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return st.stack[st.top];
}
int isEmpty(Stack st){
    if(st.top == -1){
        return 1;
    }
    return 0;
}
int isFull(Stack st){
    if(st.top == st.size - 1){
        return 1;
    }
    return 0;
}
int main(){
    Stack s;
    createStack(&s);
    push(&s, 3);
    push(&s, 4);
    push(&s, 8);
    int popped = pop(&s);
    cout<<"Popped element: "<<popped<<endl;
    push(&s, 4);
    display(s);
    cout<<s.top<<endl;
    cout<<"Element at index 1: "<<peek(s, 3)<<endl;
    return 0;
}
