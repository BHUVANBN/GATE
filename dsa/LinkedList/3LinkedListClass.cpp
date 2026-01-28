#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};
class LinkedList{
    private: 
        Node *first;
    public:
        LinkedList(){first =NULL;}
        LinkedList(int A[], int n){
            first->data = A[0]; //create first node with data and null
            first->next = NULL;
            Node *last = first; //last pointer to keep track of the last node
            for(int i=1;i<n;i++){
                Node *t = new Node; //allocates memory of size Node
                t->data = A[i];
                t->next = NULL;
                last->next = t;
                last = t;
            }
        }
        ~LinkedList(){ //destructor of linked list
            Node *p = first; //pointer to traverse the list
            while(first){
                first = first->next;
                delete p;
                p = first;
            }
        };
        void Display(){
            Node *p = first;
            while(p){
                cout << p->data << " ";
                p=p->next;
            }
            cout << endl;
        }
        int Length(){
            int count = 0;
            Node *p = first;
            while(p){
                count++;
                p=p->next;
            }
            return count;
        }
        void Insert(int index, int x){
            if(index < 0 || index > Length()){
                return;
            }
            Node *p = first; //to traverse
            Node *t = new Node; //new node with data
            t->data = x;
            t->next = NULL;
            if(index == 0){ //if inserting at the beginning
                t->next = first;
                first = t;
            }
            else{
                for(int i=0;i<index-1;i++){ //eg: to insert at position 4 we need to stop at 3
                    p = p->next;
                }
                t->next = p->next;
                p->next = t;
            }
        }
        int Delete(int index){
            if(index < 0 || index > Length()){
                return -1;
            }
            Node *p = first;
            for(int i=0;i<index;i++){
                p = p->next;
            }
            int x = p->data;
            delete p;
            return x;
        }
        
};
int main(){
    int A[] = {1,2,3,4,5};
    LinkedList ll(A,5);
    ll.Display();
    return 0;
}
