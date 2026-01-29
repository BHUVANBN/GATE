#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
class Stack{
    private:
    Node *top;
    public:
    Stack(){top = NULL;}
    ~Stack(){
        Node *p=top;
        while(p){
            top=top->next;
            delete p;
            p=top;
        }
    }
    void push(int x){
        Node *t = new Node;
        t->data=x;
        t->next=top;
        top=t;
    }
    int pop(){
        if(top==NULL) return -1;
        int x=top->data;
        Node *t=top;
        top=top->next;
        delete t;
        return x;
    }
    void display(){
        Node *p=top;
        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    int isEmpty(){
        return top==NULL;
    }
    int isFull(){
        Node *t=new Node;
        int r=t?1:0;
        delete t;
        return r;
    }
    int stackTop(){
        if(top) return top->data;
        return -1;
    }
    int peek(int index){
        if(index<0) return -1;
        Node *p=top;
        for(int i=0;i<index && p;i++) p=p->next;
        if(p) return p->data;
        return -1;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout<<s.pop()<<endl;
    s.display();
    return 0;
}