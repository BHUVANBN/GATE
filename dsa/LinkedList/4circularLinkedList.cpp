//Circular linked list is when linked list last node points to the head node
//benefits - traverse the list circularly
//if there is only one node it should point on itself
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
class CLinkedList{
    private:
        Node *head;
    public:
        CLinkedList(){head = NULL;}
        CLinkedList(int A[], int n){
            head = new Node;
            head->data = A[0];
            head->next = head;  //head itself is circular
            Node *last = head;
            for(int i = 1; i<n;i++){
                Node *t = new Node;
                t->data = A[i];
                t->next = head;//linking last node to head
                last->next = t; //previous node connects to newly created node
                last = t;      
            }
        }
        void Display(){
            Node *p = head;
            do{
                cout<<p->data<<" ";
                p=p->next;
            }while(p!=head);
            cout<<"\n";
        }
        void Insert(int index, int data){
            if(index < 0 || index > Length())
                return;
            Node *t = new Node;
            t->data = data;
            if(index == 0){
                if(head == NULL){
                    head = t; //if head is not pointing to anything i.e NULL, make it point to new node t
                    t->next = head;
                }
                else{
                    Node *p = head;
                    while(p->next != head){ //traverse till last node which is pointing to the head
                        p=p->next;
                    }
                    p->next = t;
                    t->next = head;
                    head = t;
                }
                return;
            }
            Node *p = head;
            for(int i = 1;i<index; i++){
                p = p->next;
            }
            
            t->next = p->next;
            p->next = t;
        }
        int Length(){
            int len=0;
            Node *p = head;
            do{ 
                len++;
                p = p->next;
            }while(p!=head);
            return len;
        }
        int Delete(int index){
            if(index<1||index>Length()) return -1;
            Node *p = head;
            Node *q = NULL;
            if(index==1){
                int x = head->data;
                while(p->next!=head)p=p->next; //traverse till last node
                p->next = head->next;
                head->next =NULL;
                delete head;
                head = p->next;
                return x;
            }
            p = head;
            for(int i=1; i<index; i++){
                q=p;
                p=p->next;
            }
            int x = p->data;
            q->next = p->next;
            p->next =NULL;
            delete p;
            return x;
        }
};
int main(){
    int A[]={1,2,3,4,5};
    CLinkedList cl(A,5);
    cl.Display();
    cout<<"Length is: "<<cl.Length()<<endl;

    cl.Insert(0,7);
    cl.Insert(3,12);
    cl.Display();

    cout<<"deleted element: "<<cl.Delete(1)<<endl;
    cl.Display();
    return 0;
}